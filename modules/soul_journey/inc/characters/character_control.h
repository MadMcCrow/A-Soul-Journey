/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_CHARACTER_CONTROL_H
#define ASJ_CHARACTER_CONTROL_H

#include "scene/main/node.h" // Node godot class
#include "core/notification_interface.h"
#include "static_helper.h"



/** ASJ namespace */
namespace ASJ {
    
/**
 *  CameraMove 
 *  @brief root node to move a camera around
 */
class CharacterControl : public Node, public NotificationInterface {
    GDCLASS(CharacterControl, Node);
    NOTIFICATIONS();

protected:

	static void _bind_methods();

public:

    CharacterControl();
    ~CharacterControl();

    virtual void process(float delta_time) override;
    virtual void ready() override;

    /**
     *  _unhandled_input
     *  @note  is connected via _bind_methods and "set_process_unhandled_input"
     */
    virtual void _unhandled_input(const Ref<InputEvent> &p_event, bool p_local_coords);

protected:

    /**
     *  input_zoom_in_name 
     *  @brief the name of the zoom action input, it will affect camera boom
     */
    String input_move_order_name;
    GETSET(String, input_move_order_name)


};
}; // namespace ASJ

#endif // ASJ_CHARACTER_CONTROL_H