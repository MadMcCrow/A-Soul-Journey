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

protected:

    // NotificationInterface overrides
    virtual void ready() override;
    virtual void process(float delta_time) override;

public:

    /**
     *  add_zoom_offset 
     *  @brief increase or decrease zoom
     *  @param delta how much to increase or decrease the zoom
     */
    void add_zoom_offset(float delta);

protected:

    /**
     *  zoom_speed 
     *  @brief how fast we should transition between zoom position
     */
    float zoom_speed;
    GETSET(float, zoom_speed)

    /**
     *  zoom_min 
     *  @brief how close can we get 
     */
    float zoom_min;
    GETSET(float, zoom_min)

    /**
     *  zoom_max 
     *  @brief how far can we get 
     */
    float zoom_max;
    GETSET(float, zoom_max)

    /**
     *  zoom_max 
     *  @brief how far can we get 
     */
    float zoom_input_multiplier = 1.f;
    GETSET(float, zoom_input_multiplier)


    /**
     *  curvilinear_abs_preview
     *  @brief the distance spanned on the cycloid (preview value)
     *  @note editor only preview parameter
     */
    float curvilinear_abs_target = 10.f;
    GET(float, curvilinear_abs_target)
#if TOOLS_ENABLED
    _ALWAYS_INLINE_ void SETTER(curvilinear_abs_target)(float in_curvilinear_abs_target)
    {
        curvilinear_abs_target = clamp(in_curvilinear_abs_target, zoom_min, zoom_max);
        if (Engine::get_singleton()->is_editor_hint())
        {
            curvilinear_abs = curvilinear_abs_target;
            update_boom();
        }
    }
#else
    SET(float, curvilinear_abs_target)
#endif

    /**
     *  circle radius 
     *  @brief the radius of the circle drawing the cycloid for the camera
     *  @note custom setter allows changing the length in editor.
     *        the custom setter is not compiled on shipping binary
     */
    float circle_radius = 100.f;
    GET(float, circle_radius)
#if TOOLS_ENABLED
    _ALWAYS_INLINE_ void SETTER(circle_radius)(float new_circle_radius)
    {
        circle_radius = new_circle_radius;
        update_boom();
    }
#else
    SET(float, circle_radius)
#endif


    /**
     *  circle radius 
     *  @brief the radius of the circle drawing the cycloid for the camera
     */
    float base_x_radian;
    GET(float, base_x_radian)
#if TOOLS_ENABLED
    _ALWAYS_INLINE_ void SETTER(base_x_radian)(float new_base_x_radian)
    {
        base_x_radian = new_base_x_radian;
        update_boom();
    }
#else
    SET(float, base_x_radian)
#endif

private:

    /** find position on the cycloid to then get position and rotation in world space */
    Vector2 get_position_on_cycloid();

    /** update this node rotation and childs positions */
    void update_boom();


    /** 
     *  curvilinear_abs
     *  @brief the distance spanned on the cycloid, 
     *  not exposed to the editor
     */
    float curvilinear_abs;

};

} // namespace ASJ

#endif //ASJ_CAMERA_BOOM_H
