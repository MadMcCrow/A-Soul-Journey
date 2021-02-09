/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "actors/actor_3d.h"
#include "static_helper.h"
#include "scene/scene_string_names.h"

using namespace ASJ;


Actor3D::Actor3D()
{
    connect(SceneStringNames::get_singleton()->ready, callable_mp(this, &Actor3D::ready));
    //connect(SceneStringNames::get_singleton()->tree_entered, callable_mp(this, &Actor3D::tree_update));
}

Actor3D::~Actor3D()
{
}

void Actor3D::ready()
{

}

void Actor3D::_notification(int p_notification)
{
    LOG(String::num_int64(p_notification));
    switch (p_notification)
    {
        //case NOTIFICATION_PROCESS:
        case NOTIFICATION_INTERNAL_PROCESS:
        {
            LOG("process tick called");
            if(auto* tree = get_tree())
            {
                process(tree->get_process_time());
            }
            break;    
        }
        case NOTIFICATION_PHYSICS_PROCESS:
        {
            if(auto* tree = get_tree())
            {
                physics_process(tree->get_physics_process_time());
            }
            break;  
        }
        default:
            break;
    }
}

void Actor3D::process( float delta)
{
    LOG("process called");
}

void Actor3D::physics_process(float delta)
{

}

void Actor3D::_bind_methods() 
{
}


