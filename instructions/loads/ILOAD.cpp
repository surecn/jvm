//
// Created by 郑邦国 on 2018/11/24.
//

#include "ILOAD.h"

namespace rt {

    static void _iload(Frame* frame, u1 index) {
        java_int val = frame->getLocalVars()->getInt((int)index);
        cout << " val" << val << endl;
        frame->getOperandStack()->pushInt(val);
    }

    void ILOAD::execute(rt::Frame *frame) {
        _iload(frame, m_index);
    }

    void ILOAD_0::execute(rt::Frame *frame) {
        _iload(frame, 0);
    }

    void ILOAD_1::execute(rt::Frame *frame) {
        _iload(frame, 1);
    }

    void ILOAD_2::execute(rt::Frame *frame) {
        _iload(frame, 2);
    }

    void ILOAD_3::execute(rt::Frame *frame) {
        _iload(frame, 3);
    }

}