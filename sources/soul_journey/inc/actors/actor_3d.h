/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_ACTOR_3D_H
#define ASJ_ACTOR_3D_H

#include "scene/3d/node_3d.h" // Node godot class
#include "core/script_interface.h"
/** ASJ namespace */
namespace ASJ {

/**
 *  Actor3D 
 *  @brief implements functions like Ready, Update, etc.
 *  all bindings are done in this class
 */
class Actor3D : public Node3D , public ScriptInterface {
    GDCLASS(Actor3D, Node3D);
    NOTIFICATIONS(Actor3D)
public:

    // ctr
    Actor3D();

    // dstr
    ~Actor3D();


};

} // namespace ASJ

#endif //ASJ_ACTOR_3D_H
