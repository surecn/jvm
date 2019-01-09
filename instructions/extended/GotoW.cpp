//
// Created by 郑邦国 on 2018/12/8.
//

#include "GotoW.h"

namespace rt {

    void GOTO_W::fetchOperand(rt::BytecodeReader *reader) {
        offset = reader->readU4();
    }

    void GOTO_W::execute(rt::Frame *frame) {
        branch(frame, offset);
    }

}