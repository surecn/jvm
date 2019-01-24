//
// Created by 郑邦国 on 2019/1/23.
//

#include "AccessController.h"

#include "../../Registry.h"
#include "../../../runtime/Thread.h"
#include "../../../runtime/heap/Class.h"
#include "../../../instructions/base/MethodInvokeLogic.h"

namespace native {

    void AccessController::init() {
        string className("java/security/AccessController");
        Registry::registerNative(className, "doPrivileged", "(Ljava/security/PrivilegedAction;)Ljava/lang/Object;", &(AccessController::doPrivileged));
        Registry::registerNative(className, "doPrivileged", "(Ljava/security/PrivilegedExceptionAction;)Ljava/lang/Object;", &(AccessController::doPrivileged));
    }

    void AccessController::doPrivileged(rt::Frame *frame) {
        rt::LocalVars *vars = frame->getLocalVars();
        rt::Object* ref = (rt::Object*)vars->getRef(0);
        rt::OperandStack *stack = frame->getOperandStack();
        stack->pushRef(ref);
        string methodName("run");
        string descriptor("()Ljava/lang/Object;");
        rt::Method *method = ref->getClass()->getInstanceMethod(methodName, descriptor);
        rt::MethodInvokeLogic::invokeMethod(frame, method);

    }

}