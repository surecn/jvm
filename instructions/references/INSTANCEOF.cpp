//
// Created by 郑邦国 on 2018/12/23.
//

#include "INSTANCEOF.h"
#include "../../runtime/heap/ConstantPool.h"
#include "../../runtime/heap/Class.h"
#include "../../runtime/heap/ClassRef.h"

namespace rt {

    void INSTANCEOF::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_ref ref = stack->popRef();
        if (ref == NULL) {
            stack->pushInt(0);
            return;
        }
        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
        ClassRef *classRef = (ClassRef *)cp->getConstant(m_index);
        Class *cls = classRef->resolvedClass();
        if (ref->isInstanceOf(cls)) {
            stack->pushInt(1);
        } else {
            stack->pushInt(0);
        }
    }

}