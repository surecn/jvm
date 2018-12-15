//
// Created by 郑邦国 on 2018/12/3.
//

#include "Fcmp.h"

namespace rt {

    static void _fcmp(Frame *frame, bool gFlag) {
        OperandStack* stack = frame->getOperandStack();
        java_float v2 = stack->popFloat();
        java_float v1 = stack->popFloat();
        if (v1 > v2) {
            stack->pushInt(1);
        } else if (v1 == v2) {
            stack->pushInt(0);
        } else if (v1 < v2) {
            stack->pushInt(-1);
        } else if (gFlag) {//Not a Number的情况，结果不清楚？
            stack->pushInt(1);
        } else {
            stack->pushInt(-1);
        }
    }

    void FCMPG::execute(rt::Frame *frame) {
        _fcmp(frame, true);
    }

    void FCMPL::execute(rt::Frame *frame) {
        _fcmp(frame, false);
    }

}