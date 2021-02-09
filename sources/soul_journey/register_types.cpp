/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

<<<<<<< HEAD
#include "nodes/actor_3d.h"
=======
#include "actors/actor_3d.h"
#include "actors/character.h"
#include "player/camera_control.h"
>>>>>>> 0518144 (:construction::zap: start SJ specific code)
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
<<<<<<< HEAD
  ClassDB::register_class<ASJ::Actor3D>();

=======
	ClassDB::register_class<ASJ::Actor3D>();
	ClassDB::register_class<ASJ::CameraControl>();
	ClassDB::register_class<ASJ::Character>();
>>>>>>> 0518144 (:construction::zap: start SJ specific code)
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

