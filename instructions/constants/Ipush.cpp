//
// Created by 郑邦国 on 2018/12/14.
//

#include "Ipush.h"

namespace rt {

    void BIPUSH::fetchOperand(rt::BytecodeReader *reader) {
        _val = reader->readC1();
    }

    void BIPUSH::execute(rt::Frame *frame) {
        java_int i = (java_int)this->_val;
        frame->getOperandStack()->pushInt(i);
    }

}