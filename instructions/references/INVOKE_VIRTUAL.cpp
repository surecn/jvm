//
// Created by 郑邦国 on 2018/12/26.
//

#include "INVOKE_VIRTUAL.h"
#include "../../runtime/heap/ConstantPool.h"
#include "../../runtime/heap/MethodRef.h"
#include "../../runtime/heap/MethodLookup.h"
#include "../base/MethodInvokeLogic.h"
#include "../../runtime/heap/StringPool.h"

namespace rt {

    void INVOKE_VIRTUAL::execute(rt::Frame *frame) {
        Class *currentCls = frame->getMethod()->getClass();
        ConstantPool *cp = currentCls->getConstantPool();
        MethodRef *methodRef = cp->getMethodRef(m_index);
        Class *resolvedClass = methodRef->resolvedClass();
        Method *resolvedMethod = methodRef->resolvedMethod();
        cout << "INVOKE_VIRTUAL " << *resolvedMethod->getName() << endl;
        if (*resolvedMethod->getName() == "<init>" && resolvedMethod->getClass() != resolvedClass) {
            logError("java.lang.NoSuchMethodError");
        }
        if (resolvedMethod->isStatic()) {
            logError("java.lang.IncompatibleClassChangeError");
        }
        Object* ref = (Object*)frame->getOperandStack()->getRefFromTop(resolvedMethod->getArgSlotCount() - 1);
        if (ref == NULL) {
//            // hack !
//            if (*methodRef->getName() == "println") {
//                println(frame->getOperandStack(), methodRef->getDescriptor());
//            }
            logError("java.lang.NullPointerException");
            return;
        }
        if (resolvedMethod->isProtected() &&
            resolvedMethod->getClass()->isSubClassOf(currentCls) &&
            resolvedMethod->getClass()->getPackageName() != currentCls->getPackageName() &&
            ref->getClass() != currentCls &&
            !(ref->getClass()->isSubClassOf(currentCls))) {
            logError("java.lang.IllegalAccessError");

        }
        Method *methodToBeInvoke = MethodLookup::lookupMethodInClass(ref->getClass(), methodRef->getName(), methodRef->getDescriptor());
        if (methodToBeInvoke == NULL || methodToBeInvoke->isAbstract()) {
            logError("java.lang.AbstractMethodError  " + *methodRef->getName());
            return;
        }
        MethodInvokeLogic::invokeMethod(frame, methodToBeInvoke);

//        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
//        MethodRef *methodRef = (MethodRef*)cp->getConstant(m_index);

//        }
    }

    void INVOKE_VIRTUAL::println(rt::OperandStack *stack, string *descriptor) {
        if (*(descriptor) == "(Z)V") {
            cout << stack->popInt() << endl;
        } else if (*(descriptor) == "(C)V") {
            cout << stack->popInt() << endl;
        } else if (*(descriptor) == "(C)V") {
            cout << stack->popInt() << endl;
        } else if (*(descriptor) == "(I)V") {
            cout << dec << stack->popInt() << endl;
        } else if (*(descriptor) == "(B)V") {
            cout << stack->popInt() << endl;
        } else if (*(descriptor) == "(S)V") {
            cout << stack->popInt() << endl;
        } else if (*(descriptor) == "(F)V") {
            cout << stack->popFloat() << endl;
        } else if (*(descriptor) == "(J)V") {
            cout << stack->popLong() << endl;
        } else if (*(descriptor) == "(D)V") {
            cout << stack->popDouble() << endl;
        } else if (*(descriptor) == "(Ljava/lang/String;)V") {
            Object *s = (Object *)stack->popRef();
            cout << StringPool::getCString(s) << endl;
        } else {
            cout << "println: " << *descriptor << endl;
        }
        stack->popRef();
    }

}