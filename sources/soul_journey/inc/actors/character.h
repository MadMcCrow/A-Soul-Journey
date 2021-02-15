/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_CHARACTER_H
#define ASJ_CHARACTER_H

#include "scene/3d/physics_body_3d.h" // KinematicBody3D
#include "core/script_interface.h"

/** ASJ namespace */
namespace ASJ {

/**
 *  Actor3D 
 *  @brief implements functions like Ready, Update, etc.
 *  all bindings are done in this class
 */
class Character : public KinematicBody3D, public ScriptInterface  {
    GDCLASS(Character, KinematicBody3D);
    NOTIFICATIONS(Character)

public:

    // ctr
    Character();

    // dstr
    ~Character();
};

} // namespace ASJ

#endif //ASJ_CHARACTER_H
