//
// Created by 郑邦国 on 2018/12/14.
//

#include "Ipush.h"

namespace rt {

    void BIPUSH::fetchOperand(rt::BytecodeReader *reader) {
        _val = reader->readU1();
    }

    void BIPUSH::execute(rt::Frame *frame) {
        int i = (int)this->_val;
        frame->getOperandStack()->pushInt(i);
    }

}