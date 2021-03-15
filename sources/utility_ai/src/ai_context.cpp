/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "ai_context.h"


using namespace UtilityAI;


AIContext::AIContext() : Reference()
{
    
}

AIContext::~AIContext()
{
}

void AIContext::add_context_value(String name, float value)
{
    // insert replace value on map :)
    context_values.insert(name, value);
}

void AIContext::reset()
{
    context_values.clear();
}


float AIContext::get_context_value(String name) const
{
    if (const Map<String,float>::Element * found = context_values.find(name))
    {
        return found->value();
    }
    return -1;
}


bool AIContext::value_exists(String name) const
{
    if (const Map<String,float>::Element * found = context_values.find(name))
    {
        return true;
    }
    return false;
}


std::optional<float> AIContext::get_context_value_checked(String name) const
{
    if (const Map<String,float>::Element * found = context_values.find(name))
    {
        return found->value();
    }
    return std::optional<float>(); // will be optional, thus you're sure that's not valid
}



void AIContext::_bind_methods()
{


    ClassDB::bind_method(D_METHOD( "add_context_value", "name", "value"), &AIContext::add_context_value);
    ClassDB::bind_method(D_METHOD( "get_context_value", "name"), &AIContext::get_context_value);
    ClassDB::bind_method(D_METHOD( "value_exists", "name"), &AIContext::value_exists);
    ClassDB::bind_method(D_METHOD( "reset"), &AIContext::reset);

}

