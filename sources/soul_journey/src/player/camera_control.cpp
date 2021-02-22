/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "player/camera_control.h"
#include "scene/main/viewport.h"

using namespace ASJ;


CameraControl::CameraControl() : Node3D()
{
}

CameraControl::~CameraControl()
{
}


void CameraControl::ready()
{
    set_process(true);
}

void CameraControl::process(float delta)
{
    move_on_mouse_screen_border(delta);
}

void CameraControl::unhandled_input(const Ref<InputEvent> &p_event, bool p_local_coords)
{
    LOG("input not handled !")
}

void CameraControl::move_on_mouse_screen_border(float delta)
{
    const Vector2 border = get_border_movement();
    Vector3 move_vec = Vector3(border.x, 0.f, border.y);
    global_translate(move_vec.rotated(Vector3(0.f,1.f,0.f), get_rotation_degrees().y) * move_speed * delta);
}

Vector2 CameraControl::get_border_movement() const
{
    const Vector2 view_size = get_viewport()->get_camera_rect_size();
    const Vector2 mouse_pos = get_viewport()->get_mouse_position();
    Vector2 retval = Vector2();
    if (mouse_pos.x < border_margin.x)
    {
        const float dist = (border_margin.x - mouse_pos.x) / border_margin.x ;
        retval.x = - 1.f *  dist*dist;
    }
    else if (mouse_pos.x > view_size.x - border_margin.x)
    {
        const float dist = (border_margin.x - (view_size.x - mouse_pos.x)) / border_margin.x ;
        retval.x = 1.f *  dist*dist;
    }
    if (mouse_pos.y < border_margin.y)
    {
        const float dist = (border_margin.y - mouse_pos.y) / border_margin.y ;
        retval.y = -1.f * dist*dist;
    }
    else if (mouse_pos.y > view_size.y - border_margin.y)
    {
        const float dist = (border_margin.y - (view_size.y - mouse_pos.y)) / border_margin.y ;
        retval.y = 1.f *  dist*dist;
    }
    return retval;
}

void CameraControl::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("unhandled_input", "event", "in_local_coords"), &CameraControl::unhandled_input, DEFVAL(false));
    // Properties
    BIND_PROPERTY_GETSET(CameraControl, Variant::VECTOR2I, border_margin, PROPERTY_HINT_RANGE, "0,20,1");
    BIND_PROPERTY_GETSET(CameraControl, Variant::FLOAT, move_speed, PROPERTY_HINT_RANGE, "0,100,10,1");
}


