//
// Created by 郑邦国 on 2018/12/8.
//

#include "FStore.h"

namespace rt {

    static void _fstore(Frame* frame, u1 index) {
        java_float val = frame->getOperandStack()->popFloat();
        frame->getLocalVars()->setFloat(index, val);
    }

    void FSTORE::execute(rt::Frame *frame) {
        _fstore(frame, m_index);
    }

    void FSTORE_0::execute(rt::Frame *frame) {
        _fstore(frame, 0);
    }

    void FSTORE_1::execute(rt::Frame *frame) {
        _fstore(frame, 1);
    }

    void FSTORE_2::execute(rt::Frame *frame) {
        _fstore(frame, 2);
    }

    void FSTORE_3::execute(rt::Frame *frame) {
        _fstore(frame, 3);
    }

}
