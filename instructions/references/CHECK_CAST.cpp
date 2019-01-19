//
// Created by 郑邦国 on 2018/12/23.
//

#include "CHECK_CAST.h"
#include "../../runtime/heap/ConstantPool.h"
#include "../../runtime/heap/Class.h"
#include "../../runtime/heap/ClassRef.h"

namespace rt {

    void CHECK_CAST::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_ref ref = stack->popRef();
        stack->pushRef(ref);
        if (ref == NULL) {
            return;
        }
        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
        ClassRef *classRef = cp->getClassRef(m_index);
        Class *cls = classRef->resolvedClass();
        if (!((Object*)ref)->isInstanceOf(cls)) {
            cout << "java.lang.ClassCastException" << endl;
        }
    }

}