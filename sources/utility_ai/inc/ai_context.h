/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef UTILITY_AI_CONTEXT_H
#define UTILITY_AI_CONTEXT_H

#include "core/object/reference.h" // godot class
#include <optional>

/** UtilityAI namespace */
namespace UtilityAI {

/**
 *  AIBaseNode 
 *  @brief base class for all AI resources
 */
class AIContext : public Reference{
    GDCLASS(AIContext, Reference);

    static void _bind_methods();
public:

    // ctr
    AIContext();

    // dstr
    ~AIContext();

private:

    Map<String, float> context_values;
    
public:

    /**
     *  add_context_value
     *  @brief Add or replace value stored in this context with specified name
     *  @param name     the name tag you want to associate the value with
     *  @param value    the value of that context
     */
    virtual void add_context_value(String name, float value);

    /**
     *  reset
     *  @brief remove every info stored in this context
     */
    virtual void reset();

    /**
     *  get_context_value
     *  @brief remove every info stored in this context
     *  @param name     the name of the value you want
     *  @return         the value or -1 if not defined
     */
    virtual float get_context_value(String name) const;

    /**
     *  value_exists
     *  @brief remove every info stored in this context
     *  @param name     the name of the value you want
     *  @return         true if value defined
     */
    virtual bool value_exists(String name) const;

    /**
     *  get_context_value
     *  @brief remove every info stored in this context
     *  @param name     the name of the value you want
     *  @return         the value or not defined 
     */
    virtual std::optional<float> get_context_value_checked(String name) const;


};

} // namespace UtilityAI

#endif //UTILITY_AI_CONTEXT_H
