//
// Created by 郑邦国 on 2018/11/24.
//

#include "IPush.h"

namespace rt {

    void BIPUSH::fetchOperand(rt::BytecodeReader *reader) {
        val = reader->readU1();
    }

    void BIPUSH::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushInt(val);
    }

    void SIPUSH::fetchOperand(rt::BytecodeReader *reader) {
        val = reader->readU2();
    }

    void SIPUSH::execute(rt::Frame *frame) {
        frame->getOperandStack()->pushInt(val);
    }



}


