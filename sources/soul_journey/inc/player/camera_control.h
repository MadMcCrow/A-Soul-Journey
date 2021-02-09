/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_CAMERA_H
#define ASJ_CAMERA_H

#include "actors/actor_3d.h" // Node godot class
#include "core/input/input_event.h"
#include "static_helper.h"

/** ASJ namespace */
namespace ASJ {

/**
 *  Actor3D 
 *  @brief implements functions like Ready, Update, etc.
 *  all bindings are done in this class
 */
class CameraControl : public Actor3D  {
    GDCLASS(CameraControl, Actor3D);

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

#endif //ACTOR_3D_H
