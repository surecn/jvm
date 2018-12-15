//
// Created by 郑邦国 on 2018/12/3.
//

#include "L2x.h"

namespace rt {

    void L2I::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_long dVal = stack->popLong();
        java_int fVal = (java_int)dVal;
        stack->pushInt(fVal);
    }

    void L2D::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_long dVal = stack->popLong();
        java_double fVal = (java_double)dVal;
        stack->pushDouble(fVal);
    }

    void L2F::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_long dVal = stack->popLong();
        java_float fVal = (java_float)dVal;
        stack->pushFloat(fVal);
    }
}