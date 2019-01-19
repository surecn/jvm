//
// Created by 郑邦国 on 2018/12/12.
//

#include "OR.h"

namespace rt {

    void IOR::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int val1 = stack->popInt();
        java_int val2 = stack->popInt();
        stack->pushInt(val1 | val2);
    }

    void LOR::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_long val1 = stack->popLong();
        java_long val2 = stack->popLong();
        stack->pushLong(val1 | val2);
    }



}