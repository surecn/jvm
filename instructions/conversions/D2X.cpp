//
// Created by 郑邦国 on 2018/12/3.
//

#include "D2X.h"

namespace rt {

    void D2F::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_double  dVal = stack->popDouble();
        java_float fVal = (java_float)dVal;
        stack->pushFloat(fVal);
    }

    void D2I::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_double  dVal = stack->popDouble();
        java_int fVal = (java_int)dVal;
        stack->pushInt(fVal);
    }

    void D2L::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_double  dVal = stack->popDouble();
        java_long fVal = (java_long)dVal;
        stack->pushLong(fVal);
    }


}
