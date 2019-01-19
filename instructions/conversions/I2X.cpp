//
// Created by 郑邦国 on 2018/12/3.
//

#include "I2X.h"

namespace rt {

    void I2B::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int dVal = stack->popInt();
        byte fVal = (byte)dVal;
        stack->pushInt(fVal);
    }

    void I2C::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int dVal = stack->popInt();
        short fVal = (short)dVal;
        stack->pushInt(fVal);
    }

    void I2S::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int dVal = stack->popInt();
        short fVal = (short)dVal;
        stack->pushInt(fVal);
    }

    void I2F::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int dVal = stack->popInt();
        java_float fVal = (java_float)dVal;
        stack->pushFloat(fVal);
    }

    void I2D::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int dVal = stack->popInt();
        java_double fVal = (java_double)dVal;
        stack->pushDouble(fVal);
    }

    void I2L::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int dVal = stack->popInt();
        java_long fVal = (java_long)dVal;
        stack->pushLong(fVal);
    }
}