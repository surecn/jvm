//
// Created by 郑邦国 on 2018/12/14.
//

#include "SIPUSH.h"

namespace rt {

    void SIPUSH::fetchOperand(rt::BytecodeReader *reader) {
        _val = reader->readU2();
    }

    void SIPUSH::execute(rt::Frame *frame) {
        int i = (int)this->_val;
        frame->getOperandStack()->pushInt(i);
    }

}