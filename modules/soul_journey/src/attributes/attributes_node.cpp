/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#include "attributes/attributes_node.h"

using namespace ASJ;

    // ctr
Attributes_node::Attributes_node()
{

}

    // dstr
Attributes_node::~Attributes_node()
{

}


Variant Attributes_node::get_attribute(const String& key, const Variant &fallback)
{
    if (!key_exists(key))
        return fallback;
    
    return private_attributes.find(key)->get();
}

bool Attributes_node::key_exists(const String &key)
{
    return private_attributes.has(key);
}

void Attributes_node::set_attribute(const String& key, const Variant &value)
{
    private_attributes.insert(key, value);
}


void Attributes_node::_bind_methods()
{
    ClassDB::bind_method(D_METHOD( "get_attribute", "key", "fallback"), &Attributes_node::get_attribute);
    ClassDB::bind_method(D_METHOD( "key_exists", "key"), &Attributes_node::key_exists);
    ClassDB::bind_method(D_METHOD( "set_attribute", "key", "value"), &Attributes_node::set_attribute);
}