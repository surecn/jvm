//
// Created by 郑邦国 on 2018/11/23.
//

#include "Constant.h"


namespace rt {

    void NOP::execute(rt::Frame *frame) {
        //什么都不做
    }

    void ACONST_NULL::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushRef(NULL);
    }

    void DCONST_0::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushDouble(0.0);
    }

    void DCONST_1::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushDouble(1.0);
    }

    void FCONST_0::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushFloat(0);
    }

    void FCONST_1::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushFloat(1);
    }

    void FCONST_2::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushFloat(2);
    }

    void ICONST_M1::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushInt(-1);
    }

    void ICONST_0::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushInt(0);
    }

    void ICONST_1::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushInt(1);
    }

    void ICONST_2::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushInt(2);
    }

    void ICONST_3::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushInt(3);
    }

    void ICONST_4::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushInt(4);
    }

    void ICONST_5::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushInt(5);
    }

    void LCONST_0::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushLong(0);
    }

    void LCONST_1::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushLong(1);
    }




}