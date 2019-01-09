//
// Created by 郑邦国 on 2018/12/12.
//

#include "Neg.h"

namespace rt {

    void INEG::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int val = stack->popInt();
        stack->pushInt(-val);
    }

    void LNEG::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_long val = stack->popLong();
        stack->pushLong(-val);
    }

    void FNEG::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_float val = stack->popFloat();
        stack->pushFloat(-val);
    }

    void DNEG::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_double val = stack->popDouble();
        stack->pushDouble(-val);
    }

}