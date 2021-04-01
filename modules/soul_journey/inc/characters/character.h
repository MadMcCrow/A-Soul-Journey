/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_CHARACTER_H
#define ASJ_CHARACTER_H

#include "scene/3d/physics_body_3d.h" // KinematicBody3D
#include "core/notification_interface.h"
#include "static_helper.h"

// forward declaration
class NavigationRegion3D;
class NavigationAgent3D;

/** ASJ namespace */
namespace ASJ {

/**
 *  Actor3D 
 *  @brief implements functions like Ready, Update, etc.
 *  all bindings are done in this class
 */
class Character : public KinematicBody3D, public NotificationInterface  {
    GDCLASS(Character, KinematicBody3D);
    NOTIFICATIONS()

public:

    // ctr
    Character();

    // dstr
    ~Character();

    /** overriden from @see NotificationInterface */
    virtual void ready() override;

    /** overriden from @see NotificationInterface */
    virtual void physics_process(float delta) override;

private:

    /**
     *  navigation
     *  @brief where we can move
     */
    NavigationRegion3D* navigation_region_node  = nullptr;
    

    /**
     *  navigation_agent
     *  @brief where we can move
     */
    NavigationAgent3D* navigation_agent_node = nullptr;

protected:

    /**
     *  navigation_agent
     *  @brief where we can move
     */
    float ground_ray_trace_length;
    GETSET(float, ground_ray_trace_length)

    /**
     *  navigation_agent 
     *  @brief the agent for this character
     */
    NodePath navigation_agent;
    GETSET(NodePath, navigation_agent)

    /**
     *  navigation_region 
     *  @brief the navigation region this character uses
     */
    NodePath navigation_region;
    GETSET(NodePath, navigation_region)



public:
    /**
     *  MoveTo
     *  @brief Give the path finder to find a path for us and move there 
     *  @param world_position : where you want to go
     */
    bool MoveTo(Vector3 world_position);

    /**
     *  get_ground_normal
     *  @brief get the normal right underneath us
     */
    Vector3 get_ground_normal() const;

protected:

    // will update the position of the character at physics_process
    void update_movement();

private:

    /**
     *  @brief will find navigation and save it
     */
    void initialize_navigation();

    static void _bind_methods();

};

} // namespace ASJ

#endif //ASJ_CHARACTER_H
