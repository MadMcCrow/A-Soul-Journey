/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef UTILITY_AI_CONSIDERATION_H
#define UTILITY_AI_CONSIDERATION_H

#include "ai_base_resource.h" // parent class
#include "scene/resources/curve.h"

class Curve;

/** UtilityAI namespace */
namespace UtilityAI {

/**
 *  AIBaseNode 
 *  @brief base class for all AI resources
 */
class AIConsideration : public AIBaseResource{
    GDCLASS(AIConsideration, AIBaseResource);

    static void _bind_methods();
public:

    // ctr
    AIConsideration();

    // dstr
    ~AIConsideration();

public:

    /**
     *  Evaluate
     *  @brief Get final value of that consideration
     *  @param context the context to take into account
     */
    virtual float evaluate(class AIContext* context);

     /**
     *  RawValue
     *  @brief Get raw value of that consideration
     *  basically ignore the curve and the possible normalisation
     *  @param context the context to take into account
     */
    virtual float raw_value(class AIContext* context);

protected:

    /**
     *  output_curve
     *  @brief the curve to apply to this consideration
     */
    Ref<Curve> output_curve;

    /**
     *  context_tag
     *  @brief the tag to use to find value on context
     */
    String context_tag;


public:
    _ALWAYS_INLINE_  Ref<Curve> get_output_curve() const {return output_curve;}  
    _ALWAYS_INLINE_  void       set_output_curve(Ref<Curve> curve) {output_curve = curve;}

    _ALWAYS_INLINE_  String     get_context_tag() const {return context_tag;}  
    _ALWAYS_INLINE_  void       set_context_tag(String tag) {context_tag = tag;}  


    virtual RID get_rid() const override;

};

} // namespace UtilityAI

#endif //UTILITY_AI_CONSIDERATION_H
