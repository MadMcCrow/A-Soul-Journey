/* Copyright © Noé Perard-Gayot 2021. */
/* Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php */

#ifndef UTILITY_AI_TASK_NODE_H
#define UTILITY_AI_TASK_NODE_H

#include "ai_base_node.h"
#include "ai_consideration.h"

/** UtilityAI namespace */
namespace UtilityAI {

/**
 *  AIBrainNode
 *  @brief makes decision
 */
class AITaskNode : public AIBaseNode{
    GDCLASS(AITaskNode, AIBaseNode);

	static void _bind_methods();

public:

    // ctr
    AITaskNode();

    // dstr
    ~AITaskNode();

    /**
     *  @fn can_interrupt
     *  @brief wether this task can be stopped while it runs or not
     */
    virtual bool can_interrupt() const;

    /**
     *  @fn execute
     *  @brief run this task
     *  @return true if succeeded, false otherwise
     */
    virtual bool execute();

    /**
     *  @fn feasible
     *  @brief whether this task should be executed at all
     */
    virtual bool feasible() const {return true;}

    /**
     *  @fn evaluate
     *  @brief check all our considerations to determine utility score of that task
     *  @param  context     the information we might wanna consider
     *  @return the utility score
     */
    virtual float evaluate(class AIContext* context);

protected:

    /**
     * @property    interrupt_flag
     * @brief       simple flag to set a task non-interruptable in data
     */
    bool can_interrupt_flag = true;


    /**
     * @property    considerations
     * @brief       list of consideration to evaluate to make our decision
     */
    Map<Ref<AIConsideration>, float> considerations;



#ifdef TOOLS_ENABLED
private:

    /**
     * @property    add_consideration
     * @brief       consideration to add to our map
     */
    Ref<AIConsideration> add_consideration;
    _ALWAYS_INLINE_ Ref<AIConsideration> get_add_consideration() const {return Ref<AIConsideration>();}
    _ALWAYS_INLINE_ void set_add_consideration(Ref<AIConsideration> consideration) {
        if (!Engine::get_singleton()->is_editor_hint())
            return;
        if (consideration.is_valid()) 
            considerations[consideration] = 0.f;
        // update godot view
        set_considerations(get_considerations());
        }
#endif

private:

    /** @brief storing the already calculated values here for performance @see get_consideration_value */

    _ALWAYS_INLINE_ bool get_can_interrupt_flag() const {return can_interrupt_flag;}
    _ALWAYS_INLINE_ void set_can_interrupt_flag(bool new_flag) {can_interrupt_flag = new_flag;}

    Dictionary get_considerations() const;
    void set_considerations(const Dictionary &Dict);
    
};

} // namespace UtilityAI

#endif //UTILITY_AI_TASK_NODE_H
