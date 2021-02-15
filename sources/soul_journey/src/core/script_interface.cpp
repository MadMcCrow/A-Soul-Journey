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
        this_node->set_pause_mode(Node::PAUSE_MODE_PROCESS);
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
            parented();
        }
        break;
        case Node::NOTIFICATION_READY    :
        {
            ready();
        }
        break;
        case Node::NOTIFICATION_PROCESS:
        {
            if(SceneTree * tree = _get_scene_tree(this))
                process(tree->get_process_time());
        }
        break;
        case Node::NOTIFICATION_PHYSICS_PROCESS:
        {
            if(SceneTree * tree = _get_scene_tree(this))
                physics_process(tree->get_physics_process_time());
        }
        break;
        default:
            break;
    }
}


void ScriptInterface::parented()
{
    //connect
}

void ScriptInterface::process( float delta)
{
    // nothing to do here
}

void ScriptInterface::physics_process(float delta)
{
    // nor here
}


