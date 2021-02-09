/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "actors/character.h"
#include "scene/scene_string_names.h"

using namespace ASJ;


Character::Character()
{
    connect(SceneStringNames::get_singleton()->_ready, callable_mp(this, &Character::_ready));
    connect(SceneStringNames::get_singleton()->_process, callable_mp(this, &Character::_process));
    //connect(SceneStringNames::get_singleton()->update, callable_mp(this, &Actor3D::update));
    connect(SceneStringNames::get_singleton()->tree_entered, callable_mp(this, &Character::tree_update));
}

Character::~Character()
{
}

void Character::_ready()
{

}

void Character::_process( float delta)
{

}

void Character::tree_update() 
{

}

void Character::_bind_methods() 
{

}


