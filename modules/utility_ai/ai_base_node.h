/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef UTILITY_AI_BASE_NODE_H
#define UTILITY_AI_BASE_NODE_H

#include "scene/main/node.h" // Node godot class

/** UtilityAI namespace */
namespace UtilityAI {

/**
 *  AIBaseNode 
 *  @brief base class for all AI nodes
 */
class AIBaseNode : public Node{
    GDCLASS(AIBaseNode, Node);
public:

    // ctr
    AIBaseNode();

    // dstr
    ~AIBaseNode();

};

} // namespace UtilityAI

#endif //UTILITY_AI_BASE_NODE_H
