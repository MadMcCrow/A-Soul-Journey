/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "characters/character_control.h"

using namespace ASJ;


CharacterControl::CharacterControl() : Node(), NotificationInterface()
{
}

CharacterControl::~CharacterControl()
{
}

void CharacterControl::process(float delta_time)
{

}

void CharacterControl::ready()
{
    set_physics_process(true);
    set_process_unhandled_input(true);
}

void CharacterControl::_unhandled_input(const Ref<InputEvent> &p_event, bool p_local_coords)
{

}


void CharacterControl::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("_unhandled_input", "event", "in_local_coords"), &CharacterControl::_unhandled_input, DEFVAL(false));
    BIND_PROPERTY_GETSET(CharacterControl, Variant::STRING_NAME, input_move_order_name, PROPERTY_HINT_NONE, "Name of move order input");
}
