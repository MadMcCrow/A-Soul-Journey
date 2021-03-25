/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef UTILITY_AI_BRAIN_NODE_H
#define UTILITY_AI_BRAIN_NODE_H

#include "ai_base_node.h" 
#include "ai_context.h"


/** UtilityAI namespace */
namespace UtilityAI {

class AITaskNode;

/**
 *  AIBrainNode
 *  @brief makes decision
 */
class AIBrainNode : public AIBaseNode{
    GDCLASS(AIBrainNode, AIBaseNode);
public:

    // ctr
    AIBrainNode();

    // dstr
    ~AIBrainNode();

    void _notification(int p_what);

protected:

    /**
     *  @brief send context to consideration, evaluate tasks and do something
     */
    virtual void update();

    /**
     *  @brief get all child nodes that are tasks
     */
    virtual List<AITaskNode*> get_all_tasks() const;

    /**
     *  @brief run a task as current task
     */
    virtual void execute_task(AITaskNode *task);

private:

    /**
     *  agent_context:
     *  @brief context for this brain. it will store the necessary values for this  
     */
    Ref<AIContext> agent_context;

    /**
     *  tasks:
     *  @brief all stored tasks this brain can decide to do
     */ 
    List<AITaskNode*> tasks;

    /**
     *  active_task:
     *  @brief the task currently running
     */
    AITaskNode* active_task;


};

} // namespace UtilityAI

#endif //UTILITY_AI_BRAIN_NODE_H
