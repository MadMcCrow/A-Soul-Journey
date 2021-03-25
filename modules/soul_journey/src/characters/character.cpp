/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "characters/character.h"
#include "scene/3d/navigation_agent_3d.h"
#include "scene/3d/navigation_region_3d.h"

using namespace ASJ;


Character::Character()
{
}

Character::~Character()
{
}

void Character::physics_process(float delta)
{

}

Vector3 Character::get_ground_normal() const
{
        const auto gravity_direction = Vector3(0.f, -1.f, 0.f); 
        const auto pos = get_global_transform().origin;
        const auto pos_offset = pos - gravity_direction * ground_ray_trace_length;
        PhysicsDirectSpaceState3D::RayResult TraceResult;
        auto ignore_RIDs = Set<RID>();
        ignore_RIDs.insert(get_rid());
        if (get_world_3d()->get_direct_space_state()->intersect_ray(pos, pos_offset,TraceResult, ignore_RIDs ))
        {
            return TraceResult.normal;
        }
        // default to opposite of gravity:
        return gravity_direction * -1;
}


void Character::UpdateMovement()
{
    if (navigation_agent)
    {
        const auto gravity_direction = Vector3(0.f, -1.f, 0.f); 
        const auto target = navigation_agent->get_next_location();
        const auto pos = get_global_transform().origin;

        const auto vel = (target - pos).slide(get_ground_normal()).normalized() * navigation_agent->get_max_speed();

        //TODO: Add slope calculation, speed management 
        move_and_slide(vel,gravity_direction *-1);
    }
}


void Character::_bind_methods()
{
    
}