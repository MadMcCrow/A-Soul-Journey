/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef UTILITY_AI_CONSIDERATION_H
#define UTILITY_AI_CONSIDERATION_H

#include "ai_base_resource.h" // Node godot class

/** UtilityAI namespace */
namespace UtilityAI {

/**
 *  AIBaseNode 
 *  @brief base class for all AI resources
 */
class AIConsideration : public AIBaseResource{
    GDCLASS(AIConsideration, AIBaseResource);
public:

    // ctr
    AIConsideration();

    // dstr
    ~AIConsideration();



};

} // namespace UtilityAI

#endif //UTILITY_AI_CONSIDERATION_H
