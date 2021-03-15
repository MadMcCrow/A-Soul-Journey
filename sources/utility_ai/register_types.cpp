/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */


// godot include
#include "register_types.h"

// base classes
//#include "ai_base_node.h"
//#include "ai_base_resource.h"

// usefull classes
#include "ai_brain_node.h"
#include "ai_task_node.h"
// considerations
#include "ai_consideration_value.h"


void register_utility_ai_types() 
{
	ClassDB::register_class<UtilityAI::AIBrainNode>();
	ClassDB::register_class<UtilityAI::AITaskNode>();
	ClassDB::register_class<UtilityAI::AIConsiderationValue>();
}

void unregister_utility_ai_types() 
{
}

