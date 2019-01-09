//
// Created by 郑邦国 on 2018/11/26.
//

#include "Pop.h"

namespace rt {

    void Pop::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        stack->popSlot();
    }

    void Pop2::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        stack->popSlot();
        stack->popSlot();
    }


}
