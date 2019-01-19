//
// Created by 郑邦国 on 2018/12/5.
//

#include "DCMP.h"

namespace rt {

    static void _dcmp(Frame *frame, bool gFlag) {
        OperandStack* stack = frame->getOperandStack();
        java_double v2 = stack->popDouble();
        java_double v1 = stack->popDouble();
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

    void DCMPG::execute(rt::Frame *frame) {
        _dcmp(frame, true);
    }

    void DCMPL::execute(rt::Frame *frame) {
        _dcmp(frame, false);
    }

}