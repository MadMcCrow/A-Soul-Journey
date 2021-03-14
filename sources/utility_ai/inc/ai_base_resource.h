/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef UTILITY_AI_BASE_RESOURCE_H
#define UTILITY_AI_BASE_RESOURCE_H

#include "core/io/resource.h" // Node godot class

/** UtilityAI namespace */
namespace UtilityAI {

/**
 *  AIBaseNode 
 *  @brief base class for all AI resources
 */
class AIBaseResource : public Resource{
    GDCLASS(AIBaseResource, Resource);
public:

    // ctr
    AIBaseResource();

    // dstr
    ~AIBaseResource();



};

} // namespace UtilityAI

#endif //UTILITY_AI_BASE_RESOURCE_H
