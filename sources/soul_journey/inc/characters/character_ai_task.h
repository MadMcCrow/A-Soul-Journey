/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_CHARACTER_AI_TASK_H
#define ASJ_CHARACTER_AI_TASK_H
#include "sources/utility_ai/ai_task_node.h"
#include "core/notification_interface.h"
#include "static_helper.h"



/** ASJ namespace */
namespace ASJ {
    
/**
 *  CameraMove 
 *  @brief root node to move a camera around
 */
class CharacterAITask : public UtilityAI::AITaskNode {
    GDCLASS(CharacterAITask, UtilityAI::AITaskNode);
protected:

	static void _bind_methods() {};


};
}; // namespace ASJ

#endif // ASJ_CHARACTER_AI_TASK_H