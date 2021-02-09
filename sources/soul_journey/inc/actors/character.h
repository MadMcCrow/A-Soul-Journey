/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_CHARACTER_H
#define ASJ_CHARACTER_H

#include "scene/3d/physics_body_3d.h" // KinematicBody3D

/** ASJ namespace */
namespace ASJ {

/**
 *  Actor3D 
 *  @brief implements functions like Ready, Update, etc.
 *  all bindings are done in this class
 */
class Character : public KinematicBody3D  {
    GDCLASS(Character, KinematicBody3D);

public:

    // ctr
    Character();

    // dstr
    ~Character();



    /**
     *  ready
     *  @brief called when node is ready to start doing stuff
     *  @note  is connected via signal
     */
    virtual void _ready();

    /**
     *  process
     *  @brief called each frame
     *  @param delta : deltaframe
     *  @note  is connected via _bind_methods.
     *  @todo  investigate using signals
     */
    virtual void _process(float delta);

    /**
     *  update
     *  @brief called on a change in the node tree
     *  @todo  investigate using signals
     */
    virtual void tree_update();
    

     /**
     *  _bind_methods native function : expose function to GDScript
     *  @note add the function to the reflexion API
     */
    static void _bind_methods();

};

} // namespace ASJ

#endif //ASJ_CHARACTER_H
