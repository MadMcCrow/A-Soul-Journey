/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_CAMERA_BOOM_H
#define ASJ_CAMERA_BOOM_H

#include "scene/3d/node_3d.h" // Node godot class
#include "core/notification_interface.h"
#include "core/input/input_event.h"
#include "static_helper.h"

/** ASJ namespace */
namespace ASJ {

/**
 *  CameraBoom 
 *  @brief a arm to have a camera on an offset
 */
class CameraBoom : public Node3D, public NotificationInterface {
    GDCLASS(CameraBoom, Node3D);
    NOTIFICATIONS()

protected:
	static void _bind_methods();

public:

    // ctr
    CameraBoom();

    // dstr
    ~CameraBoom();

    // NotificationInterface overrides
    virtual void ready() override;
    virtual void process(float delta_time) override;

public:
    /**
     *  arm_length 
     *  @brief how far the childs will be compared to the parent
     *  @note custom setter allows changing the length in editor.
     *        the custom setter is not compiled on shipping binary
     */
    float arm_length = 10.f;
    GET(float, arm_length)
#if TOOLS_ENABLED
    void SETTER(arm_length)(float new_arm_length)
    {
        arm_length = new_arm_length;
        update_boom();
    }
#else
    SET(float, arm_length)
#endif

protected:

    /**
     *  circle radius 
     *  @brief the radius of the circle drawing the cycloid for the camera
     */
    float circle_radius = 100.f;
    GETSET(float, circle_radius)

    /**
     *  arm_length 
     *  @brief how far the childs will be compared to the parent
     */
    float max_arm_length = 100.f;
    GETSET(float, max_arm_length)


    /**
     *  circle radius 
     *  @brief the radius of the circle drawing the cycloid for the camera
     */
    Vector3 base_rotation;
    GETSET(Vector3, base_rotation)

private:

    /** find position on the cycloid to then get position and rotation in world space */
    Vector2 get_position_on_cycloid();

    // update this node rotation and childs positions
    void update_boom();


};

} // namespace ASJ

#endif //ASJ_CAMERA_BOOM_H
