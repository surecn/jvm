//
// Created by 郑邦国 on 2018/11/27.
//

#include "Swap.h"

namespace rt {

    void Swap::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        long slot1 = stack->popSlot();
        long slot2 = stack->popSlot();
        stack->pushSlot(slot1);
        stack->pushSlot(slot2);
    }

}