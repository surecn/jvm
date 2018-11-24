//
// Created by 郑邦国 on 2018/11/24.
//

#include "ILoad.h"

namespace rt {

    ILOAD::ILOAD(int _index) : index(_index) {}

    void ILOAD::execute(rt::Frame *frame) {
        long val = frame->getLocalVars()->getInt(index);
        frame->getOperandStrack()->pushInt(val);
    }
}