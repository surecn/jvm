//
// Created by 郑邦国 on 2018/12/8.
//

#include "IStore.h"

namespace rt {

    static void _istore(Frame* frame, u1 index) {
        java_int val = frame->getOperandStack()->popInt();
        frame->getLocalVars()->setInt(index, val);
    }

    void ISTORE::execute(rt::Frame *frame) {
        _istore(frame, _index);
    }

    void ISTORE_0::execute(rt::Frame *frame) {
        _istore(frame, 0);
    }

    void ISTORE_1::execute(rt::Frame *frame) {
        _istore(frame, 1);
    }

    void ISTORE_2::execute(rt::Frame *frame) {
        _istore(frame, 2);
    }

    void ISTORE_3::execute(rt::Frame *frame) {
        _istore(frame, 3);
    }

}
