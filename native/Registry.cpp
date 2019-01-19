//
// Created by 郑邦国 on 2019/1/9.
//

#include <thread>
#include "Registry.h"
#include "../native/java/lang/JClass.h"
#include "../native/java/lang/JObject.h"
#include "java/lang/JSystem.h"
#include "java/lang/JFloat.h"
#include "java/lang/JDouble.h"
#include "java/lang/JString.h"
#include "sun/misc/JVM.h"

namespace native {

    map<string, void(*)(rt::Frame*)>* Registry::s_registry;

    Fun Registry::s_emptyNativeMethod;


    int Registry::initData = init();

    int Registry::init() {
        s_emptyNativeMethod = &(Registry::emptyNativeMethod);
        s_registry = new map<string, void(*)(rt::Frame*)>();

        JClass::init();
        JObject::init();
        JSystem::init();
        JFloat::init();
        JDouble::init();
        JString::init();
        JVM::init();
        return 1;
    }

    void Registry::registerNative(string className, string methodName, string descriptor, Fun method) {
        string key = className + "~" + methodName + "~" + descriptor;
        (*s_registry)[key] = method;
    }

    Fun Registry::findNativeMethod(string *className, string *methodName, string *descriptor) {
        string key = *className + "~" + *methodName + "~" + *descriptor;
        Fun fun = (*s_registry)[key];
        if (fun != NULL) {
            return fun;
        }
        if (*descriptor == "()V" && *methodName == "registerNatives") {
            return Registry::s_emptyNativeMethod;
        }
        return NULL;
    }

    void Registry::emptyNativeMethod(rt::Frame *frame) {
    }

}