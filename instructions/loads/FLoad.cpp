//
// Created by 郑邦国 on 2018/12/8.
//

#include "FLoad.h"

namespace rt {

    static void _fload(Frame* frame, u1 index) {
        java_float val = frame->getLocalVars()->getFloat(index);
        frame->getOperandStack()->pushFloat(val);
    }

    void FLOAD::execute(rt::Frame *frame) {
        _fload(frame, _index);
    }

    void FLOAD_0::execute(rt::Frame *frame) {
        _fload(frame, 0);
    }

    void FLOAD_1::execute(rt::Frame *frame) {
        _fload(frame, 1);
    }

    void FLOAD_2::execute(rt::Frame *frame) {
        _fload(frame, 2);
    }

    void FLOAD_3::execute(rt::Frame *frame) {
        _fload(frame, 3);
    }

}