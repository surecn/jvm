//
// Created by 郑邦国 on 2019/1/9.
//

#include <thread>
#include "Registry.h"
#include "../native/java/lang/JClass.h"
#include "../native/java/lang/JObject.h"
#include "../native/java/lang/JThrowable.h"
#include "../native/java/io/JFileOutputStream.h"
#include "../native/java/io/JFileInputStream.h"
#include "../native/java/io/JFileDescriptor.h"
#include "java/lang/JSystem.h"
#include "java/lang/JFloat.h"
#include "java/lang/JDouble.h"
#include "java/lang/JString.h"
#include "java/lang/JThread.h"
#include "java/security/AccessController.h"
#include "sun/misc/VM.h"
#include "sun/misc/JUnsafe.h"
#include "sun/reflect/JReflection.h"

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
        VM::init();
        StackTraceElement::init();
        JFileOutputStream::init();
        JFileInputStream::init();
        JFileDescriptor::init();
        JUnsafe::init();
        JReflection::init();
        AccessController::init();
        JThread::init();


//        rt::Class *_shimClass  = new rt::Class("~shim");
//        _returnCode = []byte{0xb1} // return
//        _athrowCode = []byte{0xbf} // athrow
//
//        _returnMethod = &Method{
//                ClassMember: ClassMember{
//                        accessFlags: ACC_STATIC,
//                        name:        "<return>",
//                        class:       _shimClass,
//                },
//                code: _returnCode,
//        }
//
//        _athrowMethod = &Method{
//                ClassMember: ClassMember{
//                        accessFlags: ACC_STATIC,
//                        name:        "<athrow>",
//                        class:       _shimClass,
//                },
//                code: _athrowCode,
//        }
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