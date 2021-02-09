
#include "static_helper.h"
#include "core/object/object.h"
#include "core/string/print_string.h"

<<<<<<< HEAD
void ASJ::print_msg(Object *obj, const char *txt)
=======
void ASJ::print_msg_impl(Object *obj, const char *txt)
>>>>>>> 0518144 (:construction::zap: start SJ specific code)
{
    if (obj)
    {
        auto class_name = String("[") + obj->get_class() + String("]");
        auto objet_string = String("[") + obj->to_string() + String("]");
        auto str = class_name + objet_string + String(": ") + txt;
        print_verbose(str);
        return;
    }
    print_verbose(txt);
}

<<<<<<< HEAD
void ASJ::print_msg(Object *obj, const String &txt)
=======
void ASJ::print_msg_impl(Object *obj, const String &txt)
>>>>>>> 0518144 (:construction::zap: start SJ specific code)
{
    if (obj)
    {
        auto class_name = String("[") + obj->get_class() + String("]");
        auto objet_string = String("[") + obj->to_string() + String("]");
        auto str = class_name + objet_string + String(": ") + txt;
        print_verbose(str);
        return;
    }
    print_verbose(txt);
}
