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
    arm_length = arm_length_target; 
    update_boom();
}

void CameraBoom::process(float delta)
{
    // lerp is a + t * (b - a)
    if (arm_length_target != arm_length)
    {
        arm_length = lerp(zoom_speed * delta, arm_length, arm_length_target);
        update_boom();
    }
}

void CameraBoom::add_zoom_offset(float delta)
{
    arm_length_target = clamp(arm_length_target + (delta * zoom_input_multiplier), zoom_min, zoom_max);
}

Vector2 CameraBoom::get_position_on_curve()
{
    // y = b(x/c)³
    // (√(x² +b(x/c)³))+a = 0
    // a = -1* L²
    // b has little effect.
    // c will affect a lot the curve
    // https://www.wolframalpha.com/input/?i=solve+%28%E2%88%9A%28x%C2%B2+%2Bb%28x%2Fc%29%C2%B3%29%29%2Ba+%3D+0
    constexpr auto cbrt =[](float x ){return pow(x, 1.f/3.f);};
    const float c = curve_ratio;
    const float a =  - 1 * arm_length * arm_length;
    const float b = 1; // first ratio parameter, has little importance
    const float cbrtx = cbrt(27*a*a*b*c*c*c + 5.19615 * sqrt(27*a*a*a*a*b*b*b*b*c*c*c*c*c*c - 4*a*a*b*b*pow(c,12)) - 2*pow(c,9));
    const float x = 0.333333 * ((1.25992* pow(c,6))/(b* cbrtx) + (0.793701* cbrtx)/b - c*c*c/b);

    const float y = pow(x/c,3)*b;
    return Vector2 (x,y);
}

void CameraBoom::update_boom()
{
    // get info :
    Vector2 cyclo = get_position_on_curve();

    const float angle  = cyclo.angle() + base_x_radian;
    const float length = arm_length;
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
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, arm_length_target, PROPERTY_HINT_RANGE,  "1,200,1,1");
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, curve_ratio,   PROPERTY_HINT_RANGE,      "1,200,1,1");
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, base_x_radian,   PROPERTY_HINT_RANGE,    "0,3.141459,0.314159,1");

    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, zoom_speed, PROPERTY_HINT_RANGE,  "0,200,10,1");
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, zoom_min,   PROPERTY_HINT_RANGE,  "0.1,200,10,1");
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, zoom_max,   PROPERTY_HINT_RANGE,  "0.1,200,10,1");

    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, zoom_input_multiplier,   PROPERTY_HINT_RANGE,  "1,10,1,1");
}