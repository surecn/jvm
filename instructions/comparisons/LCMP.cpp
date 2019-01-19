//
// Created by 郑邦国 on 2018/12/3.
//

#include "LCMP.h"

namespace rt {

    void LCMP::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_long v2 = stack->popLong();
        java_long v1 = stack->popLong();
        if (v1 > v2) {
            stack->pushInt(1);
        } else if (v1 == v2) {
            stack->pushInt(0);
        } else {
            stack->pushInt(-1);
        }
    }

}