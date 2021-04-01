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

void Character::ready()
{
    set_physics_process(true);
    initialize_navigation();
}

void Character::physics_process(float delta)
{
    if (is_inside_tree())
        update_movement();
    
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


void Character::update_movement()
{
    if (navigation_agent_node != nullptr)
    {
        const auto gravity_direction = Vector3(0.f, -1.f, 0.f);
        const auto target = navigation_agent_node->get_next_location();
        const auto pos = get_global_transform().origin;
        const auto vel = (target - pos).slide(get_ground_normal()).normalized() * navigation_agent_node->get_max_speed();
        move_and_slide(vel, gravity_direction * -1, false, 4 /* max slope*/, Math::deg2rad(45.f) /* max slope angle*/, false /*infinite inertia */ );
    }
}


void Character::initialize_navigation()
{
 
    navigation_agent_node  = Cast<NavigationAgent3D>(get_node(navigation_agent));
    navigation_region_node = Cast<NavigationRegion3D>(get_node(navigation_region));
#ifdef TOOLS_ENABLED
    if (navigation_region_node == nullptr)
    {
        print_error(String(__func__) + String(" : Could not find Navigation Region 3D in tree"));
    }

    if (navigation_agent_node == nullptr)
    {
        print_error(String(__func__) + String(" : Could not find Navigation Agent 3D in tree"));
    }
#endif // TOOLS_ENABLED
}


void Character::_bind_methods()
{
    BIND_PROPERTY_GETSET(Character, Variant::NODE_PATH, navigation_agent, PROPERTY_HINT_NODE_PATH_VALID_TYPES, "NavigationAgent3D");
    BIND_PROPERTY_GETSET(Character, Variant::NODE_PATH, navigation_region, PROPERTY_HINT_NODE_PATH_VALID_TYPES, "NavigationRegion3D");
}