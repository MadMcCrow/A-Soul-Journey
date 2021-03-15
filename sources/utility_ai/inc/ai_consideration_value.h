/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef UTILITY_AI_CONSIDERATION_VALUE_H
#define UTILITY_AI_CONSIDERATION_VALUE_H

#include "ai_consideration.h" // parent class


class Curve;

/** UtilityAI namespace */
namespace UtilityAI {

/**
 *  AIBaseNode 
 *  @brief base class for all AI resources
 */
class AIConsiderationValue : public AIConsideration{
    GDCLASS(AIConsiderationValue, AIConsideration);

    static void _bind_methods();
public:

    // ctr
    AIConsiderationValue();

    // dstr
    ~AIConsiderationValue();

    // @see AIConsideration
    virtual float RawValue(class AIContext* context) override;

protected:

    String context_tag;

public:

    _ALWAYS_INLINE_  String     get_context_tag() const {return context_tag;}  
    _ALWAYS_INLINE_  void       set_context_tag(String tag) {context_tag = tag;}  

};

} // namespace UtilityAI

#endif //UTILITY_AI_CONSIDERATION_VALUE_H
