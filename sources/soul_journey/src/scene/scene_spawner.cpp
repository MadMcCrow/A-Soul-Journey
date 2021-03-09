/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "scene/scene_spawner.h"

using namespace ASJ;



SceneSpawner::SceneSpawner() : pool_spawn_count(1)
{
}

SceneSpawner::~SceneSpawner()
{

}


void SceneSpawner::ready()
{
    spawn_scenes();
}

#if TOOLS_ENABLED
void SceneSpawner::editor_ready()
{
    spawn_scenes();
}
#endif // TOOLS_ENABLED

void SceneSpawner::spawn_scenes()
{
    if (sub_scene.is_valid())
    {
        for (unsigned int idx = 0; idx<pool_spawn_count; idx++)
        {
            if(spawned_scenes.size() <= idx)
            {
                Node * scene_instance = sub_scene->instance();
                spawned_scenes.append(scene_instance);
                add_child(scene_instance);
            }
        }
    }
}

void SceneSpawner::_bind_methods()
{
    ADD_GROUP("Spawner", "spawner_");
    BIND_PROPERTY_GETSET(SceneSpawner, Variant::OBJECT, sub_scene, PROPERTY_HINT_RESOURCE_TYPE, "PackedScene");
    BIND_PROPERTY_GETSET(SceneSpawner, Variant::INT, pool_spawn_count, PROPERTY_HINT_RANGE, "1,100,1,0");
}
