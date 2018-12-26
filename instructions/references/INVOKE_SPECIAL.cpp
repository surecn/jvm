//
// Created by 郑邦国 on 2018/12/26.
//

#include "INVOKE_SPECIAL.h"


namespace rt {

    void INVOKE_SPECIAL::execute(rt::Frame *frame) {
        frame->getOperandStack()->popRef();
    }

}