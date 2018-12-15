//
// Created by 郑邦国 on 2018/12/8.
//

#include "ALoad.h"

namespace rt {

    static void _aload(Frame* frame, u1 index) {
        java_ref val = frame->getLocalVars()->getRef(index);
        frame->getOperandStack()->pushRef(val);
    }

    void ALOAD::execute(rt::Frame *frame) {
        _aload(frame, _index);
    }

    void ALOAD_0::execute(rt::Frame *frame) {
        _aload(frame, 0);
    }

    void ALOAD_1::execute(rt::Frame *frame) {
        _aload(frame, 1);
    }

    void ALOAD_2::execute(rt::Frame *frame) {
        _aload(frame, 2);
    }

    void ALOAD_3::execute(rt::Frame *frame) {
        _aload(frame, 3);
    }


}