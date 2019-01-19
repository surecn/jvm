//
// Created by 郑邦国 on 2018/12/12.
//

#include "SUB.h"

namespace rt {

    void ISUB::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int val2 = stack->popInt();
        java_int val1 = stack->popInt();
        stack->pushInt(val1 - val2);
    }

    void LSUB::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_long val2 = stack->popLong();
        java_long val1 = stack->popLong();
        stack->pushLong(val1 - val2);
    }

    void FSUB::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_float val2 = stack->popFloat();
        java_float val1 = stack->popFloat();
        stack->pushFloat(val1 - val2);
    }

    void DSUB::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_double val2 = stack->popDouble();
        java_double val1 = stack->popDouble();
        stack->pushDouble(val1 - val2);
    }

}
