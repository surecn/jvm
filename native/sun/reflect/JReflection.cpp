//
// Created by 郑邦国 on 2019/1/23.
//

#include "JReflection.h"
#include "../../Registry.h"
#include "../../../runtime/Thread.h"
#include "../../../runtime/heap/Class.h"

namespace native {

    void JReflection::init() {
        string className("sun/reflect/Reflection");
        Registry::registerNative(className, "getCallerClass", "()Ljava/lang/Class;", &(JReflection::getCallerClass));
    }

    void JReflection::getCallerClass(rt::Frame *frame) {
        rt::Frame *top = frame->getThread()->getFrames()->top();
        rt::Frame *callerFrame = top->m_lower->m_lower;
        rt::Object *callerClass = callerFrame->getMethod()->getClass()->getJClass();
        frame->getOperandStack()->pushRef(callerClass);
    }

}