//
// Created by 郑邦国 on 2019/1/9.
//

#include "JClass.h"
#include "../../../runtime/heap/Object.h"
#include "../../../runtime/heap/Class.h"
#include "../../../runtime/heap/StringPool.h"
#include "../../../runtime/heap/Object.h"
#include "../../../runtime/heap/ArrayClass.h"


namespace native {

    void JClass::init() {
        string nameGetPrimitiveClass("getPrimitiveClass"), descriptorGetPrimitiveClass("(Ljava/lang/String;)Ljava/lang/Class;"),
            nameGetName0("getName0"), descriptorGetName0("()Ljava/lang/String;"),
            nameDesiredAssertionStatus0("desiredAssertionStatus0"), descriptorDesiredAssertionStatus0("(Ljava/lang/Class;)Z"),
            clsName("java/lang/Class");

        Registry::registerNative(clsName, nameGetPrimitiveClass, descriptorGetPrimitiveClass, &(JClass::getPrimitiveClass));
        Registry::registerNative(clsName, nameGetName0, descriptorGetName0, &(JClass::getName0));
        Registry::registerNative(clsName, nameDesiredAssertionStatus0, descriptorDesiredAssertionStatus0, &(JClass::desiredAssertionStatus0));
        //native.Register(jlClass, "isInterface", "()Z", isInterface)
        //native.Register(jlClass, "isPrimitive", "()Z", isPrimitive)

        Registry::registerNative(clsName, "getComponentType", "()Ljava/lang/Class;", &(JClass::getComponentType));

    }

    void JClass::getPrimitiveClass(rt::Frame *frame) {
        rt::Object *nameObj = (rt::Object*)frame->getLocalVars()->getRef(0);
        string name = rt::StringPool::getCString(nameObj);

        rt::ClassLoader *classLoader = frame->getMethod()->getClass()->getClassLoader();
        rt::Object *jclass = classLoader->loadClass(&name)->getJClass();

        frame->getOperandStack()->pushRef(jclass);
    }

    void JClass::getName0(rt::Frame *frame) {
        rt::Object *self = frame->getLocalVars()->getThis();
        rt::Class *cls = (rt::Class *)self->getExtra();

        string name = cls->getJavaName();
        rt::Object *nameObj = rt::StringPool::getJString(cls->getClassLoader(), name);
        frame->getOperandStack()->pushRef(nameObj);
    }

    void JClass::desiredAssertionStatus0(rt::Frame *frame) {
        frame->getOperandStack()->pushBoolean(false);
    }

    void JClass::getComponentType(rt::Frame *frame) {
        rt::LocalVars *localVars = frame->getLocalVars();
        rt::Object *self = localVars->getThis();
        rt::ArrayClass *arrayClass = (rt::ArrayClass*)self->getExtra();
        rt::Class *componentCls = arrayClass->getComponentClass();
        rt::Object *componentClsObj = componentCls->getJClass();
        rt::OperandStack *stack = frame->getOperandStack();
        stack->pushRef(componentClsObj);
    }

}