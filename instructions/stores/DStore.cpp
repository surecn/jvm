//
// Created by 郑邦国 on 2018/12/8.
//

#include "DStore.h"

namespace rt {

    static void _dstore(Frame* frame, u1 index) {
        java_double val = frame->getOperandStack()->popDouble();
        frame->getLocalVars()->setDouble(index, val);
    }

    void DSTORE::execute(rt::Frame *frame) {
        _dstore(frame, m_index);
    }

    void DSTORE_0::execute(rt::Frame *frame) {
        _dstore(frame, 0);
    }

    void DSTORE_1::execute(rt::Frame *frame) {
        _dstore(frame, 1);
    }

    void DSTORE_2::execute(rt::Frame *frame) {
        _dstore(frame, 2);
    }

    void DSTORE_3::execute(rt::Frame *frame) {
        _dstore(frame, 3);
    }

}