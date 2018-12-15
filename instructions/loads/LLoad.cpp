//
// Created by 郑邦国 on 2018/12/8.
//

#include "LLoad.h"

namespace rt {

    static void _iload(Frame* frame, u1 index) {
        java_long val = frame->getLocalVars()->getLong(index);
        frame->getOperandStack()->pushLong(val);
    }

    void LLOAD::execute(rt::Frame *frame) {
        _iload(frame, _index);
    }

    void LLOAD_0::execute(rt::Frame *frame) {
        _iload(frame, 0);
    }

    void LLOAD_1::execute(rt::Frame *frame) {
        _iload(frame, 1);
    }

    void LLOAD_2::execute(rt::Frame *frame) {
        _iload(frame, 2);
    }

    void LLOAD_3::execute(rt::Frame *frame) {
        _iload(frame, 3);
    }

}