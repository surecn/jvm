//
// Created by 郑邦国 on 2018/12/8.
//

#include "AStore.h"

namespace rt {

    static void _astore(Frame* frame, u1 index) {
        java_ref val = frame->getOperandStack()->popRef();
        frame->getLocalVars()->setRef(index, val);
    }

    void ASTORE::execute(rt::Frame *frame) {
        _astore(frame, _index);
    }

    void ASTORE_0::execute(rt::Frame *frame) {
        _astore(frame, 0);
    }

    void ASTORE_1::execute(rt::Frame *frame) {
        _astore(frame, 1);
    }

    void ASTORE_2::execute(rt::Frame *frame) {
        _astore(frame, 2);
    }

    void ASTORE_3::execute(rt::Frame *frame) {
        _astore(frame, 3);
    }

}