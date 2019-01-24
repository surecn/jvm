//
// Created by 郑邦国 on 2019/1/18.
//

#include "VM.h"
#include "../../Registry.h"
#include "../../../runtime/heap/Class.h"
#include "../../../runtime/heap/StringPool.h"
#include "../../../runtime/heap/ClassLoader.h"
#include "../../../instructions/base/MethodInvokeLogic.h"

namespace native {

    void VM::init() {
        string clsName("sun/misc/VM");
        string methodName("initialize");
        string methodDescriptor("()V");
        Registry::registerNative(clsName, methodName, methodDescriptor, &VM::initialize);
    }

    void VM::initialize(rt::Frame *frame) {
        rt::ClassLoader *classLoader = frame->getMethod()->getClass()->getClassLoader();
        string clsName = "java/lang/System";
        string methodName = "initializeSystemClass";
        string desName = "()V";
        rt::Class *jlSysClass = classLoader->loadClass(&clsName);
        rt::Method *initSysClass = jlSysClass->getStaticMethod(&methodName, &desName);
        rt::MethodInvokeLogic::invokeMethod(frame, initSysClass);
//        rt::Class *vmClass = frame->getMethod()->getClass();
//        string methodName("savedProps");
//        string descriptor("Ljava/util/Properties;");
//        rt::Object *savedProps = vmClass->getRefVar(methodName, descriptor);
//        rt::Object *key = rt::StringPool::getJString(vmClass->getClassLoader(), "foo");
//        rt::Object *val = rt::StringPool::getJString(vmClass->getClassLoader(), "bar");
//
//        frame->getOperandStack()->pushRef(savedProps);
//        frame->getOperandStack()->pushRef(key);
//        frame->getOperandStack()->pushRef(val);
//
//        string propertiesClassName("java/util/Properties");
//        rt::Class *propsClass = vmClass->getClassLoader()->loadClass(&propertiesClassName);
//        string propertyName("setProperty");
//        string propertyDescriptor("Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;");
//        rt::Method *method = propsClass->getInstanceMethod(propertyName, propertyDescriptor);
//        rt::MethodInvokeLogic::invokeMethod(frame, method);
    }

}