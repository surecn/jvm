//
// Created by 郑邦国 on 2018/12/30.
//

#include "INVOKE_INTERFACE.h"
#include "../../runtime/heap/Class.h"
#include "../../runtime/heap/InterfaceMethodRef.h"
#include "../../runtime/heap/MethodLookup.h"
#include "../base/MethodInvokeLogic.h"
#include "../../runtime/heap/Class.h"
#include "../../runtime/heap/ConstantPool.h"

namespace rt {

    void INVOKE_INTERFACE::fetchOperand(rt::BytecodeReader *reader) {
        m_index = (u4)(reader->readU2());
        reader->readU1();
        reader->readU1();
    }

    void INVOKE_INTERFACE::execute(rt::Frame *frame) {
        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
        InterfaceMethodRef *interfaceMethod = cp->getInterfaceMethodRef(m_index);
        Method *resolvedMethod = interfaceMethod->resolvedInterfaceMethod();
        if (resolvedMethod->isStatic() || resolvedMethod->isPrivate()) {
            logError("IncompactibleClassChangeError");
        }
        Object *ref = (Object *)frame->getOperandStack()->getRefFromTop(resolvedMethod->getArgSlotCount() - 1);
        if (ref == NULL) {
            logError("java.lang.NullPointerException");
        }
        if (!ref->getClass()->isImplements(interfaceMethod->resolvedClass())) {
            logError("IncompactibleClassChangeError");
        }
        Method *methodToBeInvoke = MethodLookup::lookupMethodInClass(ref->getClass(), interfaceMethod->getName(), interfaceMethod->getDescriptor());
        if (methodToBeInvoke == NULL || methodToBeInvoke->isAbstract()) {
            logError("java.lang.AbstractMethodError");
        }
        if (!methodToBeInvoke->isPublic()) {
            logError("java.lang.IllegalAccessError");
        }
        MethodInvokeLogic::invokeMethod(frame, methodToBeInvoke);
    }



}