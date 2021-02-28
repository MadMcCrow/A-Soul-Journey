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
     *  arm_length_target
     *  @brief the distance spanned on the cycloid (preview value)
     *  @note editor only preview parameter
     */
    float arm_length_target = 10.f;
    GET(float, arm_length_target)
#if TOOLS_ENABLED
    _ALWAYS_INLINE_ void SETTER(arm_length_target)(float in_arm_length_target)
    {
        arm_length_target = clamp(in_arm_length_target, zoom_min, zoom_max);
        if (Engine::get_singleton()->is_editor_hint())
        {
            arm_length = in_arm_length_target;
            update_boom();
        }
    }
#else
    SET(float, arm_length_target)
#endif

    /**
     *  curve_ratio  
     *  @brief how buch to bend the camera curve
     *  @note custom setter allows changing the length in editor.
     *        the custom setter is not compiled on shipping binary
     */
    float curve_ratio = 4.f;
    GET(float, curve_ratio)
#if TOOLS_ENABLED
    _ALWAYS_INLINE_ void SETTER(curve_ratio)(float in_curve_ratio)
    {
        curve_ratio = in_curve_ratio;
        update_boom();
    }
#else
    SET(float, curve_ratio)
#endif


    /**
     *  base_x_radian 
     *  @brief how much to add to x rotation, in radians
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
    Vector2 get_position_on_curve();

    /** update this node rotation and childs positions */
    void update_boom();


    /** 
     *  arm_length
     *  @brief the length of the camera arm/boom
     *  not exposed to the editor
     */
    float arm_length;

};

} // namespace ASJ

#endif //ASJ_CAMERA_BOOM_H
