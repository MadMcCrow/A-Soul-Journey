/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_SCENE_SPAWNER_H
#define ASJ_SCENE_SPAWNER_H

#include "scene/main/node.h" // Node godot class
#include "scene/resources/packed_scene.h"
#include "core/notification_interface.h"
#include "static_helper.h"

/** ASJ namespace */
namespace ASJ {

/**
 *  Actor3D 
 *  @brief implements functions like Ready, Update, etc.
 *  all bindings are done in this class
 */
class SceneSpawner : public Node , public NotificationInterface {
    GDCLASS(SceneSpawner, Node);
    NOTIFICATIONS()

    static void _bind_methods();

public:

    // ctr
    SceneSpawner();

    // dstr
    ~SceneSpawner();


protected:

    /**
     *  SubScene  
     *  @brief The scene that will be loaded and spawned by this node
     */
    Ref<PackedScene> sub_scene;
    GETSET_COPY(Ref<PackedScene>, sub_scene)

    /**
     *  pool_spawn_count  
     *  @brief how many to spawn for pooling
     */
    unsigned int pool_spawn_count;
    GETSET_COPY(unsigned int, pool_spawn_count)

    // ready is overriden to spawn at ready, and then enabled/used when really needed
    virtual void ready() override;

#if TOOLS_ENABLED
    virtual void editor_ready() override;
#endif // TOOLS_ENABLED


private:
    /**
     *  sub_scene  
     *  @brief reference to the subscene resource
     */
    //Ref<PackedScene> sub_scene;

    /**
     *  spawned_scenes  
     *  @brief VLA of spawned nodes
     */
    Vector<Node*> spawned_scenes;

    void spawn_scenes();

};

} // namespace ASJ

#endif //ASJ_SCENE_SPAWNER_H
