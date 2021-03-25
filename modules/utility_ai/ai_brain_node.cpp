/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "ai_brain_node.h"
#include "ai_task_node.h"

using namespace UtilityAI;


AIBrainNode::AIBrainNode() : AIBaseNode()
{
    agent_context.instance();
}

AIBrainNode::~AIBrainNode()
{
    agent_context.unref();
}


 void AIBrainNode::_notification(int p_what)
 { 
     switch (p_what)
     {
     case Node::NOTIFICATION_PROCESS :
         update();
         break;
    case Node::NOTIFICATION_PARENTED:
	case Node::NOTIFICATION_UNPARENTED:
    case Node::NOTIFICATION_POST_ENTER_TREE:
        tasks = get_all_tasks();
     default:
         break;
     }
 }

void AIBrainNode::update()
{
    if (active_task != nullptr)
    {
        if (!active_task->can_interrupt())
            return;
    }

    AITaskNode* best_task = nullptr;
    float best_task_value = -1.f;

    for (int idx = 0; idx< tasks.size(); idx ++)
    {
        if(tasks[idx] == nullptr)
            continue;

        const float task_value = tasks[idx]->evaluate(agent_context.ptr());
        if (task_value > best_task_value)
        {
            best_task = tasks[idx];
            best_task_value = task_value;
        }
    }

    if (best_task)
    {
      execute_task(best_task);
    }

    return;
}

List<AITaskNode*> AIBrainNode::get_all_tasks() const
{
    List<AITaskNode*> task_nodes;
    for (int idx = 0; idx < get_child_count(); idx ++ )
    {
       if (auto task = Object::cast_to<AITaskNode>(get_child(idx)))
       {
           task_nodes.push_back(task);
       }
    }
    return task_nodes;
}

void AIBrainNode::execute_task(AITaskNode *task)
{
    
}
