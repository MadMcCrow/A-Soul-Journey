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
    virtual float Evaluate(class AIContext* context);

     /**
     *  RawValue
     *  @brief Get raw value of that consideration
     *  basically ignore the curve and the possible normalisation
     *  @param context the context to take into account
     */
    virtual float RawValue(class AIContext* context);

protected:

    Ref<Curve> output_curve;

public:
    _ALWAYS_INLINE_  Ref<Curve> get_output_curve() const {return output_curve;}  
    _ALWAYS_INLINE_  void       set_output_curve(Ref<Curve> curve) {output_curve = curve;}

};

} // namespace UtilityAI

#endif //UTILITY_AI_CONSIDERATION_H
