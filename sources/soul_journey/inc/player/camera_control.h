/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_CAMERA_CONTROL_H
#define ASJ_CAMERA_CONTROL_H

#include "scene/3d/node_3d.h" // Node godot class
#include "core/notification_interface.h"
#include "core/input/input_event.h"
#include "static_helper.h"

/** ASJ namespace */
namespace ASJ {

/**
 *  CameraControl 
 *  @brief root node to move a camera around
 */
class CameraControl : public Node3D, public NotificationInterface {
    GDCLASS(CameraControl, Node3D);
    NOTIFICATIONS()

protected:
	static void _bind_methods();

public:

    // ctr
    CameraControl();

    // dstr
    ~CameraControl();

public:

    virtual void ready() override;

    virtual void process(float delta) override;

    /**
     *  _unhandled_input
     *  @note  is connected via _bind_methods
     */
    virtual void unhandled_input(const Ref<InputEvent> &p_event, bool p_local_coords);

    /**
     *  move_on_mouse_screen_border
     *  @param delta : how much time has passed sincce last frame
     *  @note  called at process
     */
    void move_on_mouse_screen_border(float delta);

public:

    /**
     *  get_border_movement
     *  @return 2D vector of camera movement, in screen space
     */
    virtual Vector2 get_border_movement() const;



protected:

    /**
     *  border_margin 
     *  @brief how many pixels are considered border (for movement detection)
     */
    Point2i border_margin = Point2i(10,10);
    GETSET(Point2i, border_margin)

    /**
     *  move_speed 
     *  @brief how fast this camera moves
     */
    float move_speed = 10;
    GETSET(float, move_speed)


};

} // namespace ASJ

#endif //ASJ_CAMERA_CONTROL_H
