//
// Created by 郑邦国 on 2018/12/8.
//

#include "LStore.h"
#include "../../runtime/Frame.h"

namespace rt {

    static void _lstore(Frame* frame, u1 index) {
        java_long val = frame->getOperandStack()->popLong();
        frame->getLocalVars()->setLong(index, val);
    }

    void LSTORE::execute(rt::Frame *frame) {
        _lstore(frame, m_index);
    }

    void LSTORE_0::execute(rt::Frame *frame) {
        _lstore(frame, 0);
    }

    void LSTORE_1::execute(rt::Frame *frame) {
        _lstore(frame, 1);
    }

    void LSTORE_2::execute(rt::Frame *frame) {
        _lstore(frame, 2);
    }

    void LSTORE_3::execute(rt::Frame *frame) {
        _lstore(frame, 3);
    }

}
