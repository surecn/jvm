//
// Created by 郑邦国 on 2018/12/26.
//

#include "INVOKE_SPECIAL.h"
#include "../../runtime/heap/ConstantPool.h"
#include "../../runtime/heap/MethodRef.h"
#include "../../runtime/heap/ClassRef.h"
#include "../../runtime/heap/MethodLookup.h"
#include "../base/MethodInvokeLogic.h"

namespace rt {

    void INVOKE_SPECIAL::execute(rt::Frame *frame) {
        Class *currentCls = frame->getMethod()->getClass();
        ConstantPool *cp = currentCls->getConstantPool();
        MethodRef *methodRef = cp->getMethodRef(m_index);
        Class *resolvedClass = methodRef->resolvedClass();
        Method *resolvedMethod = methodRef->resolvedMethod();
        if (*resolvedMethod->getName() == "<init>" && resolvedMethod->getClass() != resolvedClass) {
            logError("java.lang.NoSuchMethodError");
        }
        if (resolvedMethod->isStatic()) {
            logError("java.lang.IncompatibleClassChangeError");
        }
        Object* ref = (Object*)frame->getOperandStack()->getRefFromTop(resolvedMethod->getArgSlotCount() - 1);
        if (ref == NULL) {
            logError("java.lang.NullPointerException");
        }
        if (resolvedMethod->isProtected() &&
            resolvedMethod->getClass()->isSubClassOf(currentCls) &&
            resolvedMethod->getClass()->getPackageName() != currentCls->getPackageName() &&
            ref->getClass() != currentCls &&
            !(ref->getClass()->isSubClassOf(currentCls))) {//TODO 最后一个条件不太理解
            logError("java.lang.IllegalAccessError");
        }
        Method *methodToBeInvoke = resolvedMethod;
        if (currentCls->isSuper() &&
            resolvedClass->isSuperClassOf(currentCls) &&
            *resolvedMethod->getName() != "<init>") {
            methodToBeInvoke = MethodLookup::lookupMethodInClass(currentCls->getSuperClass(), methodRef->getName(), methodRef->getDescriptor());
        }
        if (methodToBeInvoke == NULL || methodToBeInvoke->isAbstract()) {
            logError("java.lang.AbstractMethodError");
        }
        MethodInvokeLogic::invokeMethod(frame, methodToBeInvoke);
    }

}