/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

// ASJ includes
#include "core/script_interface.h"
#include "static_helper.h"
// Godot includes
#include "scene/main/node.h"
#include "scene/main/scene_tree.h"
#include "scene/scene_string_names.h"

using namespace ASJ;

Node* _get_underlying_node(ScriptInterface * interface)
{
    if (Node* ret_node = dynamic_cast<Node*>(interface))
    {
        return ret_node;
    }
    return nullptr;
}

SceneTree* _get_scene_tree(ScriptInterface * interface)
{
    if (Node* ret_node = dynamic_cast<Node*>(interface))
    {
        return ret_node->get_tree();
    }
    return nullptr;
}

ScriptInterface::ScriptInterface()
{
    if (Node* this_node = _get_underlying_node(this))
    {
        //this_node->connect(SceneStringNames::get_singleton()->ready, callable_mp(this, &ScriptInterface::ready));
        //this_node->connect(SceneStringNames::get_singleton()->tree_entered, callable_mp(this, &Actor3D::tree_update))
    }
}

ScriptInterface::~ScriptInterface()
{
}

void ScriptInterface::ready()
{

}

void ScriptInterface::_notification_call(int p_notification)
{
    switch (p_notification)
    {
        case Node::NOTIFICATION_PARENTED :
        {
            _connect_signals();
        }
        break;
        case Node::NOTIFICATION_READY    :
        {
            ready();
        }
        break;
        // this does not work
        /*
        case Node::NOTIFICATION_PROCESS:
        break;
        case Node::NOTIFICATION_PHYSICS_PROCESS:
        break;
        */   
        default:
            break;
    }
}


void ScriptInterface::_parented_script_interface()
{
    //connect
}

void ScriptInterface::process( float delta)
{
    // nothing to do here
}

void ScriptInterface::physics_process(float delta)
{
    // nnor here
}


