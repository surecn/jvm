//
// Created by 郑邦国 on 2018/11/30.
//

#include "And.h"

namespace rt {

    void LAND::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_long v2 = stack->popLong();
        java_long v1 = stack->popLong();
        java_long result = v1 & v2;
        stack->pushLong(result);
    }

    void IAND::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int v2 = stack->popInt();
        java_int v1 = stack->popInt();
        java_int result = v1 & v2;
        stack->pushInt(result);
    }

}