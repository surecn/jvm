//
// Created by 郑邦国 on 2018/11/23.
//

#include "Constant.h"


namespace rt {

    void NOP::execute(rt::Frame *frame) {
        //什么都不做
    }

    void ACONST_NULL::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushRef(NULL);
    }

    void DCONST_0::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushDouble(0.0);
    }

    void DCONST_1::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushDouble(1.0);
    }

    void FCONST_0::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushFloat(0);
    }

    void FCONST_1::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushFloat(1);
    }

    void ICONST_M1::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushInt(-1);
    }

    void ICONST_0::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushInt(0);
    }

    void ICONST_1::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushInt(1);
    }

    void ICONST_2::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushInt(2);
    }

    void ICONST_3::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushInt(3);
    }

    void ICONST_4::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushInt(4);
    }

    void ICONST_5::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushInt(5);
    }

    void LCONST_0::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushLong(0);
    }

    void LCONST_1::execute(rt::Frame *frame) {
        frame->getOperandStrack()->pushLong(1);
    }




}