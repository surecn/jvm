//
// Created by 郑邦国 on 2018/12/5.
//

#include "Ifcond.h"

namespace rt {

    void IFEQ::execute(rt::Frame *frame) {
        java_int val = frame->getOperandStack()->popInt();
        if (val == 0) {
            branch(frame, _offset);
        }
    }

    void IFNE::execute(rt::Frame *frame) {
        java_int val = frame->getOperandStack()->popInt();
        if (val != 0) {
            branch(frame, _offset);
        }
    }

    void IFLT::execute(rt::Frame *frame) {
        java_int val = frame->getOperandStack()->popInt();
        if (val < 0) {
            branch(frame, _offset);
        }
    }

    void IFLE::execute(rt::Frame *frame) {
        java_int val = frame->getOperandStack()->popInt();
        if (val <= 0) {
            branch(frame, _offset);
        }
    }

    void IFGT::execute(rt::Frame *frame) {
        java_int val = frame->getOperandStack()->popInt();
        if (val > 0) {
            branch(frame, _offset);
        }
    }

    void IFGE::execute(rt::Frame *frame) {
        java_int val = frame->getOperandStack()->popInt();
        if (val >= 0) {
            branch(frame, _offset);
        }
    }

}