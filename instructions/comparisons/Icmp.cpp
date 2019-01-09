//
// Created by 郑邦国 on 2018/12/5.
//

#include "Icmp.h"

namespace rt {

    void ICMP::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int v2 = stack->popInt();
        java_int v1 = stack->popInt();
        if (v1 > v2) {
            stack->pushInt(1);
        } else if (v1 == v2) {
            stack->pushInt(0);
        } else {
            stack->pushInt(-1);
        }
    }

}