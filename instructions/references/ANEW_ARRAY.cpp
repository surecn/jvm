//
// Created by 郑邦国 on 2019/1/4.
//

#include "ANEW_ARRAY.h"
#include "../../runtime/heap/Class.h"
#include "../../runtime/heap/ConstantPool.h"
#include "../../runtime/heap/ClassRef.h"
#include "../../runtime/heap/ArrayClass.h"

namespace rt {

    void ANEW_ARRAY::execute(rt::Frame *frame) {
        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
        ClassRef *classRef = cp->getClassRef(ANEW_ARRAY::m_index);
        Class *compoentClass = classRef->resolvedClass();
        OperandStack *stack = frame->getOperandStack();
        java_int count = stack->popInt();
        if (count < 0) {
            logError("java.lang.NegativeArraySizeException");
        }
        ArrayClass *arrayClass = compoentClass->getArrayClass();
        Object *arr = arrayClass->newArrayObject(count);
        stack->pushRef(arr);
    }



}