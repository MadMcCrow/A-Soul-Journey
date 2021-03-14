/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef UTILITY_AI_TASK_NODE_H
#define UTILITY_AI_TASK_NODE_H

#include "ai_base_node.h" 

/** UtilityAI namespace */
namespace UtilityAI {

/**
 *  AIBrainNode
 *  @brief makes decision
 */
class AITaskNode : public AIBaseNode{
    GDCLASS(AITaskNode, AIBaseNode);
public:

    // ctr
    AITaskNode();

    // dstr
    ~AITaskNode();



};

} // namespace UtilityAI

#endif //UTILITY_AI_TASK_NODE_H
