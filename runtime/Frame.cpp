//
// Created by 郑邦国 on 2018/11/22.
//

#include "Frame.h"

namespace rt {

    Frame::Frame()  {}

    Frame* Frame::newFrame(int maxLocal, int maxStack) {
        return new Frame();
    }

    LocalVars* Frame::getLocalVars() {
        return localVars;
    }

    OperandStack* Frame::getOperandStack() {
        return operandStack;
    }
}