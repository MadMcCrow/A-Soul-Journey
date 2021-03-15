/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "core/object/object.h"
#include "ai_consideration_value.h"
#include "ai_context.h"

using namespace UtilityAI;

AIConsiderationValue::AIConsiderationValue() : AIConsideration()
{
    
}

AIConsiderationValue::~AIConsiderationValue()
{
}

float AIConsiderationValue::RawValue(AIContext* context)
{
    if (context)
    {
        return context->get_context_value_checked(get_context_tag()).value_or(0);
    }
    return 0;
}

void AIConsiderationValue::_bind_methods()
{
    ClassDB::bind_method(D_METHOD( "set_context_tag", "tag"), &AIConsiderationValue::set_context_tag);
    ClassDB::bind_method(D_METHOD( "get_context_tag"), &AIConsiderationValue::get_context_tag);
    ADD_PROPERTY(PropertyInfo( Variant::STRING, "context_tag", PROPERTY_HINT_NONE, "Tag for value"), "set_context_tag", "get_context_tag" );
}

