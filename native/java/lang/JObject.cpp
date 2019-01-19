//
// Created by 郑邦国 on 2019/1/9.
//

#include "JObject.h"
#include "../../../runtime/heap/Object.h"
#include "../../../runtime/heap/Class.h"
#include "../../../runtime/heap/ClassLoader.h"

namespace native {

    void JObject::init() {
        string clsName("java/lang/Object");
        string methodName("getClass");
        string methodDescriptor("()Ljava/lang/Class;");
        Registry::registerNative(clsName, methodName, methodDescriptor, &(JObject::getClass));
        Registry::registerNative(clsName, "hashCode", "()I", &(JObject::hashCode));
        Registry::registerNative(clsName, "clone", "()Ljava/lang/Object;", &(JObject::clone));
    }

    void JObject::getClass(rt::Frame *frame) {
        rt::Object *self = frame->getLocalVars()->getThis();
        rt::Object *jclass = self->getClass()->getJClass();
        frame->getOperandStack()->pushRef(jclass);
    }

    void JObject::hashCode(rt::Frame *frame) {
        rt::Object *obj = frame->getLocalVars()->getThis();
        java_int objInt = (java_int)obj;
        frame->getOperandStack()->pushInt(objInt);
    }

    void JObject::clone(rt::Frame *frame) {
        rt::Object *self = frame->getLocalVars()->getThis();
        string clsName = "java/lang/Cloneable";
        rt::Class *cloneable = self->getClass()->getClassLoader()->loadClass(&clsName);
        if (!self->getClass()->isImplements(cloneable)) {
            logError("java.lang.CloneNotSupportedException");
        }
        frame->getOperandStack()->pushRef(self->clone());
    }
}
