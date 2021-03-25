/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef ASJ_ATTRIBUTES_NODE_H
#define ASJ_ATTRIBUTES_NODE_H

#include "scene/main/node.h" // Node godot class
#include "static_helper.h"

/** ASJ namespace */
namespace ASJ {

/**
 *  Attributes_node 
 *  @brief attributes are map of values for gameplay
 */
class Attributes_node : public Node {
    GDCLASS(Attributes_node, Node);
protected:

	static void _bind_methods();

public:

    // ctr
    Attributes_node();
    // dstr
    ~Attributes_node();

private:
    /**
     *  private_attributes 
     *  @brief the stored map you'll be accessing
     */
    Map<String, Variant> private_attributes;

public:

    /**
     *  get attribute associated with String 
     *  @param  key     : the associated key
     *  @param  fallback : fallback value to use
     *  @return the value associated with key or default if non-existant
     */
    Variant get_attribute(const String& key, const Variant &fallback);

    /**
     *  is a value is associated with this key
     *  @param  key     : the associated key
     *  @return true if there is a value, false otherwise
     */
    bool key_exists(const String &key);

    /**
     *  is a value is associated with this key
     *  @param  key     : the associated key
     *  @param  value   : the value to use
     *  @return true if there is a value, false otherwise
     */
    void set_attribute(const String& key, const Variant &value);

};

} // namespace ASJ

#endif //ASJ_ATTRIBUTES_NODE_H
