//
// Created by 郑邦国 on 2018/12/3.
//

#include "F2x.h"

namespace rt {

    void F2I::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_float dVal = stack->popFloat();
        java_int fVal = (java_int)dVal;
        stack->pushInt(fVal);
    }

    void F2D::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_float dVal = stack->popFloat();
        java_double fVal = (java_double)dVal;
        stack->pushDouble(fVal);
    }

    void F2L::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_float dVal = stack->popFloat();
        java_long fVal = (java_long)dVal;
        stack->pushLong(fVal);
    }
}