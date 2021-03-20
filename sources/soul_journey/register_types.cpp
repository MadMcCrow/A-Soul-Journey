/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

// Camera classes
#include "camera/camera_input.h"
#include "camera/camera_move.h"
#include "camera/camera_boom.h"
// Actors classes
#include "actors/actor_3d.h"
// Character classes
#include "characters/character.h"
#include "characters/character_control.h"
#include "characters/character_ai_task_move.h"
// Scene classes
#include "scene/scene_spawner.h"
// godot include
#include "register_types.h"

#ifdef TOOLS_ENABLED
//#include "editor/resource_importer_tile_mesh.h"
#endif //TOOLS_ENABLED

#ifdef TOOLS_ENABLED
template<typename Class>
void _register_soul_journey_importer()
{
	//Ref<Class> import;
	//import.instance();
	//ResourceFormatImporter::get_singleton()->add_importer(import);
}
#endif // TOOLS_ENABLED

void register_soul_journey_types() 
{
	// Camera Types
	ClassDB::register_class<ASJ::CameraInput>();
	ClassDB::register_class<ASJ::CameraMove>();
	ClassDB::register_class<ASJ::CameraBoom>();
	ClassDB::register_class<ASJ::Actor3D>();
	ClassDB::register_class<ASJ::Character>();
	ClassDB::register_class<ASJ::CharacterControl>();
	ClassDB::register_class<ASJ::CharacterAITaskMove>();
	ClassDB::register_class<ASJ::SceneSpawner>();

#ifdef TOOLS_ENABLED
if (Engine::get_singleton()->is_editor_hint()) 
{
//	_register_asj_importer<ASJ::ResourceImporterTileMesh>();
}
#endif
}

void unregister_soul_journey_types() 
{
}

