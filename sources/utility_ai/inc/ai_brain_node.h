/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef UTILITY_AI_BRAIN_NODE_H
#define UTILITY_AI_BRAIN_NODE_H

#include "ai_base_node.h" 

/** UtilityAI namespace */
namespace UtilityAI {

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



};

} // namespace UtilityAI

#endif //UTILITY_AI_BRAIN_NODE_H
