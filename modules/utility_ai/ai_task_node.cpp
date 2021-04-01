/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "ai_task_node.h"

using namespace UtilityAI;


AITaskNode::AITaskNode() : AIBaseNode()
{
}

AITaskNode::~AITaskNode()
{
}

bool AITaskNode::can_interrupt() const
{
    return can_interrupt_flag;
}

bool AITaskNode::execute()
{
    return true;
}

float AITaskNode::evaluate(class AIContext* context)
{
    List<float> scores;
    for(int idx = 0; idx< considerations.size(); idx++)
    {
        
        /*
        if (considerations.get_key_at_index(idx).get_type() == Variant::OBJECT)
        {
            Object* obj = considerations.get_key_at_index(idx);
            if (auto * res = Object::cast_to<AIConsideration>(obj) )
            {
                scores.push_back(res->evaluate(context));
            }
        }
        */
    }

    return -1;
}


Dictionary AITaskNode::get_considerations() const
{
    Dictionary godot_dict;
    Map<Ref<AIConsideration>, float>::Element* elem = considerations.front();
    while(elem != nullptr)
    {   
        godot_dict[ elem->key()] =  elem->value();
        elem = elem->next();
    }
    return godot_dict;
}

void AITaskNode::set_considerations(const Dictionary &Dict)
{
    for (int idx = 0; idx < Dict.size(); idx++)
    {
        auto key = Dict.get_key_at_index(idx);
        auto value = Dict.get_value_at_index(idx);
        if (!key.is_ref())
            continue;

        if(AIConsideration* temp = Object::cast_to<AIConsideration>(key))
        {
            if (considerations.has(Ref<AIConsideration>(temp)))
            {
                considerations[Ref<AIConsideration>(temp)] = float(value);
            }
            else
            {
                considerations.insert(Ref<AIConsideration>(temp), value);
            }
        }
    }

}

void AITaskNode::_bind_methods()
{
    ClassDB::bind_method(D_METHOD( "set_can_interrupt_flag", "can_interrupt_flag"), &AITaskNode::set_can_interrupt_flag);
    ClassDB::bind_method(D_METHOD( "get_can_interrupt_flag"), &AITaskNode::get_can_interrupt_flag);

    ClassDB::bind_method(D_METHOD( "set_considerations", "considerations"), &AITaskNode::set_considerations);
    ClassDB::bind_method(D_METHOD( "get_considerations"), &AITaskNode::get_considerations);

    ADD_PROPERTY(PropertyInfo( Variant::BOOL, "can_interrupt_flag", PROPERTY_HINT_NONE, ""), "set_can_interrupt_flag", "get_can_interrupt_flag" );
    ADD_PROPERTY(PropertyInfo( Variant::DICTIONARY, "considerations", PROPERTY_HINT_NONE, "" ), "set_considerations", "get_considerations" );

#ifdef TOOLS_ENABLED
    if (Engine::get_singleton()->is_editor_hint())
    {
        ClassDB::bind_method(D_METHOD( "set_add_consideration", "consideration"), &AITaskNode::set_add_consideration);
        ClassDB::bind_method(D_METHOD( "get_add_consideration"), &AITaskNode::get_add_consideration);
        ADD_PROPERTY(PropertyInfo( Variant::OBJECT, "add_consideration", PROPERTY_HINT_RESOURCE_TYPE, "AIConsideration"  ), "set_add_consideration", "get_add_consideration" );
    }
#endif

}