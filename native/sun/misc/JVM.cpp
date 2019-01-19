//
// Created by 郑邦国 on 2019/1/18.
//

#include "JVM.h"
#include "../../Registry.h"
#include "../../../runtime/heap/Class.h"
#include "../../../runtime/heap/StringPool.h"
#include "../../../instructions/base/MethodInvokeLogic.h"

namespace native {

    void JVM::init() {
        string clsName("sun/misc/JVM");
        string methodName("initialize");
        string methodDescriptor("()V");
        Registry::registerNative(clsName, methodName, methodDescriptor, &JVM::initialize);
    }

    void JVM::initialize(rt::Frame *frame) {
        rt::Class *vmClass = frame->getMethod()->getClass();
        string methodName("savedProps");
        string descriptor("Ljava/util/Properties;");
        rt::Object *savedProps = vmClass->getRefVar(methodName, descriptor);
        rt::Object *key = rt::StringPool::getJString(vmClass->getClassLoader(), "foo");
        rt::Object *val = rt::StringPool::getJString(vmClass->getClassLoader(), "bar");

        frame->getOperandStack()->pushRef(savedProps);
        frame->getOperandStack()->pushRef(key);
        frame->getOperandStack()->pushRef(val);

        string propertiesClassName("java/util/Properties");
        rt::Class *propsClass = vmClass->getClassLoader()->loadClass(&propertiesClassName);
        string propertyName("setProperty");
        string propertyDescriptor("Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;");
        rt::Method *method = propsClass->getInstanceMethod(propertyName, propertyDescriptor);
        rt::MethodInvokeLogic::invokeMethod(frame, method);
    }

}