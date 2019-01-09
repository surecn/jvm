//
// Created by 郑邦国 on 2018/12/8.
//

#include "DLoad.h"

namespace rt {

    static void _dload(Frame* frame, u1 index) {
        java_double val = frame->getLocalVars()->getDouble(index);
        frame->getOperandStack()->pushDouble(val);
    }

    void DLOAD::execute(rt::Frame *frame) {
        _dload(frame, m_index);
    }

    void DLOAD_0::execute(rt::Frame *frame) {
        _dload(frame, 0);
    }

    void DLOAD_1::execute(rt::Frame *frame) {
        _dload(frame, 1);
    }

    void DLOAD_2::execute(rt::Frame *frame) {
        _dload(frame, 2);
    }

    void DLOAD_3::execute(rt::Frame *frame) {
        _dload(frame, 3);
    }

}