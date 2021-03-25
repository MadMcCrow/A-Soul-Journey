/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "camera/camera_move.h"
#include "scene/main/viewport.h"

using namespace ASJ;


CameraMove::CameraMove() : Node3D()
{
}

CameraMove::~CameraMove()
{
}


void CameraMove::ready()
{
    set_physics_process(true);
}

void CameraMove::physics_process(float delta)
{
   
}

void CameraMove::_bind_methods()
{
    BIND_PROPERTY_GETSET(CameraMove, Variant::FLOAT, move_speed, PROPERTY_HINT_RANGE, "0,100,10,1");
}


