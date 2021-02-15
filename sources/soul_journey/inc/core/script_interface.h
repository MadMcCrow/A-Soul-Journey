/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_SCRIPT_INTERFACE_H
#define ASJ_SCRIPT_INTERFACE_H

#include "scene/main/node.h"
#include "scene/scene_string_names.h"



/**
 *  Notification macro to make classes receive notifications
 */
#define NOTIFICATIONS(class) \
        void _notification(int p_what){_notification_call(p_what);} 
        /*\
        virtual void _process_script_interface(float delta) {process(delta);} \
        virtual void _physics_process_script_interface(float delta) {physics_process(delta);} \
        virtual void _connect_signals() override \
        { if (SceneTree* tree =get_tree()){ \
            tree->connect(SceneStringNames::get_singleton()->_process, \
            callable_mp(static_cast<class*>(this), &class::_process_script_interface)); \
            tree->connect(SceneStringNames::get_singleton()->_physics_process,\
            callable_mp(static_cast<class*>(this), &class::_physics_process_script_interface)); \
        }} \
        */



/** ASJ namespace */
namespace ASJ {

/**
 *  ScriptInterface : allows making scripting in C++ 
 *  @brief implements functions like Ready, Update, etc.
 *  all bindings are done in this class, so you just need to inherit from it
 *  @note 
 */
class ScriptInterface {

public:

    // ctr
    ScriptInterface();

    // dstr
    ~ScriptInterface();

//  here are the interface functions 
protected:
    /**
     *  _notification_call
     *  @brief call update functions based on notifications
     */
    virtual void _notification_call(int p_notification);

private:

// here are the scripting events you should override :
public:

    /**
     *  parented
     *  @brief called when node is has been added to the tree to start doing stuff
     *  @note  is connected via notifications
     */
    virtual void parented();

    /**
     *  ready
     *  @brief called when node is ready to start doing stuff
     *  @note  is connected via notifications
     */
    virtual void ready();

    /**
     *  process
     *  @brief called each frame
     *  @param delta : deltaframe
     *  @note  is connected via notifications
     */
    virtual void process(float delta);

    /**
     *  physics_process
     *  @brief called each physics step
     *  @param delta : deltatime between steps
     *  @note  is connected via notifications
     */
    virtual void physics_process(float delta);

};

} // namespace ASJ

#endif //ASJ_SCRIPT_INTERFACE_H
