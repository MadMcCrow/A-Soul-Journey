/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_CAMERA_MOVE_H
#define ASJ_CAMERA_MOVE_H

#include "scene/3d/node_3d.h" // Node godot class
#include "core/notification_interface.h"
#include "core/input/input_event.h"
#include "static_helper.h"

/** ASJ namespace */
namespace ASJ {

/**
 *  CameraMove 
 *  @brief root node to move a camera around
 */
class CameraMove : public Node3D, public NotificationInterface {
    GDCLASS(CameraMove, Node3D);
    NOTIFICATIONS()

protected:
	static void _bind_methods();

public:

    // ctr
    CameraMove();

    // dstr
    ~CameraMove();

protected:

    virtual void ready() override;

    virtual void physics_process(float delta) override;


public:

    /**
     *  AddMoveInput
     *  @brief ask the camera to move in a direction 
     */
    void AddMoveInput(const Vector2 &Direction);

protected:

    /**
     *  move_speed 
     *  @brief how fast this camera moves
     */
    float move_speed = 10;
    GETSET(float, move_speed)

    /**
     *  CameraBoom 
     *  @brief the camera boom that we have in our child tree
     */
    NodePath CameraBoom;
    GETSET(NodePath, CameraBoom)


};

} // namespace ASJ

#endif //ASJ_CAMERA_MOVE_H
