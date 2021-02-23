/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "camera/camera_boom.h"
using namespace ASJ;


CameraBoom::CameraBoom() : Node3D(), NotificationInterface()
{
}

CameraBoom::~CameraBoom()
{
}

void CameraBoom::ready()
{
    set_process(true);
    curvilinear_abs_target = curvilinear_abs;
    update_boom();
}

void CameraBoom::process(float delta)
{
    // lerp is a + t * (b - a)
    if (curvilinear_abs_target != curvilinear_abs)
    {
        //curvilinear_abs = curvilinear_abs + (zoom_speed * delta) * (curvilinear_abs_target - curvilinear_abs);
        curvilinear_abs = lerp(zoom_speed * delta, curvilinear_abs, curvilinear_abs_target);
        update_boom();
    }
}

void CameraBoom::add_zoom_offset(float delta)
{
    curvilinear_abs_target = clamp(curvilinear_abs_target + (delta * zoom_input_multiplier), zoom_min, zoom_max);
}

Vector2 CameraBoom::get_position_on_cycloid()
{
    // EN : https://en.wikipedia.org/wiki/Cycloid
    // FR : https://fr.wikipedia.org/wiki/Cyclo%C3%AFde
    // first let's assume that we're on the top of the (inversed) cycloid.
    // since we use curvilinear distance, the max value is 4R (whole arch is 8R)
    // this is not mathematically correct, but we'll stick with it , as it looks cool
    const float rotation_radian = (2 * 3.141592653f * curvilinear_abs) / (8 * circle_radius);
    float y = circle_radius * (rotation_radian - sin(rotation_radian));
    float x = circle_radius * ( 1 - cos (rotation_radian));
    // just inverse the curve then
    return Vector2(x, -1 * y);
}

void CameraBoom::update_boom()
{
    // get info :
    Vector2 cyclo = get_position_on_cycloid();
    const float angle  = cyclo.angle() + base_x_radian;
    const float length = cyclo.length();
    // we choose x as rotation and z as translation
    // set rotation on us
    set_rotation(Vector3(angle,0.f,0.f) );
    // and translation on childs
    for (int c = get_child_count() -1 ; c>=0; c--)
    {
        if (Node3D* child = Cast<Node3D>(get_child(c)))
        {
            child->set_translation(Vector3(0.f,0.f,length));
        }
    }
}

void CameraBoom::_bind_methods()
{
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, curvilinear_abs_target, PROPERTY_HINT_RANGE,  "0.1,200,10,1");
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, circle_radius,   PROPERTY_HINT_RANGE,  "0,200,10,1");
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, base_x_radian,   PROPERTY_HINT_RANGE,  "0,2,0.314159,1");

    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, zoom_speed, PROPERTY_HINT_RANGE,  "0,200,10,1");
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, zoom_min,   PROPERTY_HINT_RANGE,  "0.1,200,10,1");
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, zoom_max,   PROPERTY_HINT_RANGE,  "0.1,200,10,1");

    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, zoom_input_multiplier,   PROPERTY_HINT_RANGE,  "1,10,1,1");
}