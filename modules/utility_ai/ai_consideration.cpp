/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "ai_consideration.h"
#include "ai_context.h"

using namespace UtilityAI;


AIConsideration::AIConsideration() : AIBaseResource()
{
    
}

AIConsideration::~AIConsideration()
{
}


float AIConsideration::evaluate(AIContext* context)
{
    if (output_curve.is_valid())
    {
        // will bake the curve if necessary
        return output_curve->interpolate_baked(raw_value(context));
    }
    return raw_value(context);
}

float AIConsideration::raw_value(AIContext* context)
{
    if (context != nullptr && context->value_exists(get_context_tag()))
    {
        return context->get_context_value(get_context_tag());
    }
    return 0;
}

void AIConsideration::_bind_methods()
{
    ClassDB::bind_method(D_METHOD( "set_output_curve", "output_curve"), &AIConsideration::set_output_curve);
    ClassDB::bind_method(D_METHOD( "get_output_curve"), &AIConsideration::get_output_curve);

    ClassDB::bind_method(D_METHOD( "set_context_tag", "tag"), &AIConsideration::set_context_tag);
    ClassDB::bind_method(D_METHOD( "get_context_tag"), &AIConsideration::get_context_tag);

    ADD_PROPERTY(PropertyInfo( Variant::OBJECT, "output_curve", PROPERTY_HINT_RESOURCE_TYPE, "Curve"), "set_output_curve", "get_output_curve" );
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "context_tag", PROPERTY_HINT_NONE, "Tag for value"), "set_context_tag", "get_context_tag" );
}


RID AIConsideration::get_rid() const
{   
    String unique_hash_name;
    if (output_curve.is_valid())
    {
        const int count = output_curve->get_point_count();
        for (int idx = 0; idx < count; idx ++)
        {
            auto point = output_curve->get_point(idx);
            unique_hash_name += String(point.pos) + itos(int(point.left_mode)) + itos(int(point.right_mode)) + itos(int(point.right_tangent))+ itos(int(point.left_tangent));
        }
    }
    return RID::from_uint64(unique_hash_name.hash64());
}
