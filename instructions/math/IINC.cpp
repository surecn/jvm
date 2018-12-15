//
// Created by 郑邦国 on 2018/11/30.
//

#include "IINC.h"

namespace rt {

    void IINC::setIndex(u4 index) {
        _index = index;
    }

    void IINC::setConstant(java_int val) {
        constant = val;
    }

    void IINC::execute(rt::Frame *frame) {
        LocalVars *localVars = frame->getLocalVars();
        int val = localVars->getInt(_index);
        val += constant;
        localVars->setInt(_index, val);
    }

    void IINC::fetchOperand(rt::BytecodeReader *reader) {
        _index = uint(reader->readU1());
        constant = java_int(reader->readU4());
    }


}