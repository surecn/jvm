//
// Created by 郑邦国 on 2019/1/5.
//

#include "ARRAY_LENGTH.h"
#include "../../runtime/heap/Object.h"

namespace rt {

    void ARRAY_LENGTH::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_ref ref = stack->popRef();
        if (ref == NULL) {
            logError("java.lang.NullPointerException");
        }
        Object *obj = (Object*)ref;
        java_int length = obj->getArrayLength();
        stack->pushInt(length);
    }


}