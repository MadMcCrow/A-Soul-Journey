/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "player/camera_boom.h"
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
}

void CameraBoom::process(float delta)
{

}

void CameraBoom::_bind_methods()
{
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, arm_length,     PROPERTY_HINT_RANGE, "0,200,10,1");
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, max_arm_length, PROPERTY_HINT_RANGE, "0,200,10,1");
    BIND_PROPERTY_GETSET(CameraBoom, Variant::FLOAT, circle_radius,  PROPERTY_HINT_RANGE, "0,200,10,1");
    BIND_PROPERTY_GETSET(CameraBoom, Variant::VECTOR3, base_rotation, PROPERTY_HINT_NONE, "base rotation to add to the cycloid");
}

Vector2 CameraBoom::get_position_on_cycloid()
{
    // EN : https://en.wikipedia.org/wiki/Cycloid
    // FR : https://fr.wikipedia.org/wiki/Cyclo%C3%AFde
    // first let's assume that we're on the top of the (inversed) cycloid.
    // that's gonna be our sarting condition because the center of the
    // rotating circle will be exactly under  (or in our case above)
    // we then assume that our max length is at the bottom (cusps)
    // of the (inversed) cycloid
    // this implies a 180 degree angle, or pi radians
    float rotation_radian = (arm_length / max_arm_length) / 2;
    float x = circle_radius * (rotation_radian - sin(rotation_radian));
    float y = circle_radius * ( 1 - cos (rotation_radian));
    return Vector2(x,y);
}

void CameraBoom::update_boom()
{
    // get info :
    Vector2 cyclo = get_position_on_cycloid();
    const float angle  = cyclo.angle();
    const float length = cyclo.length();
    // we choose x as rotation and z as translation
    // set rotation on us
    set_rotation(Vector3(angle,0.f,0.f) +  base_rotation);
    // and translation on childs
    for (int c = get_child_count() -1 ; c>=0; c--)
    {
        if (Node3D* child = Cast<Node3D>(get_child(c)))
        {
            child->set_translation(Vector3(0.f,0.f,length));
        }
    }
}