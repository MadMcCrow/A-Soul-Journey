/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_ACTOR_3D_H
#define ASJ_ACTOR_3D_H

#include "scene/3d/node_3d.h" // Node godot class

/** ASJ namespace */
namespace ASJ {

/**
 *  Actor3D 
 *  @brief implements functions like Ready, Update, etc.
 *  all bindings are done in this class
 */
class Actor3D : public Node3D  {
    GDCLASS(Actor3D, Node3D);

public:

    // ctr
    Actor3D();

    // dstr
    ~Actor3D();

    /**
     *  _notification
     *  @brief call update functions based on notifications
     */
   	void _notification(int p_notification);
    /**
     *  ready
     *  @brief called when node is ready to start doing stuff
     *  @note  is connected via signal
     */
    virtual void ready();

    /**
     *  process
     *  @brief called each frame
     *  @param delta : deltaframe
     *  @note  is connected via _notification.
     */
    virtual void process(float delta);

    /**
     *  process
     *  @brief called each frame
     *  @param delta : deltaframe
     *  @note  is connected via _notification.
     */
    virtual void physics_process(float delta);

     /**
     *  _bind_methods native function : expose function to GDScript
     *  @note add the function to the reflexion API
     */
    static void _bind_methods();

};

} // namespace ASJ

#endif //ASJ_ACTOR_3D_H
