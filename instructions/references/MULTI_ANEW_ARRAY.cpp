//
// Created by 郑邦国 on 2019/1/5.
//

#include "MULTI_ANEW_ARRAY.h"
#include "../../runtime/heap/Class.h"
#include "../../runtime/heap/ConstantPool.h"
#include "../../runtime/heap/ClassRef.h"
#include "../../runtime/heap/ArrayClass.h"

namespace rt {

    static void popAndCheckCounts(OperandStack *stack, int dimensions, java_int **counts) {
        *counts = new java_int[dimensions];
        for (int i = dimensions; i > 0 ; --i) {
            *counts[0] = stack->popInt();
            if (*counts[0] < 0) {
                logError("java.lang.NegativeArraySizeException");
            }
        }
    }

    static Object *newMultiDimensionalArray(java_int **counts, ArrayClass *arrayClass) {
        java_int count = (*counts)[0];
        Object *obj = arrayClass->newArrayObject(count);
        if (count > 1) {
            refArray refArray = obj->getRefs();
            for (int i = 0, len = obj->getArrayLength(); i < len; ++i) {
                java_int *newCounts = new java_int[count - 1];
                refArray[i] = newMultiDimensionalArray(&newCounts, arrayClass);
            }
        }
        return obj;
    }

    void MULTI_ANEW_ARRAY::fetchOperand(rt::BytecodeReader *reader) {
        m_index = reader->readU2();
        m_dimensions = reader->readU1();
    }

    void MULTI_ANEW_ARRAY::execute(rt::Frame *frame) {
        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
        ClassRef *ref = cp->getClassRef(m_index);
        ArrayClass *arrayClass = (ArrayClass *)ref->resolvedClass();
        OperandStack *stack = frame->getOperandStack();
        java_int *count;
        popAndCheckCounts(stack, m_dimensions, &count);

    }


}