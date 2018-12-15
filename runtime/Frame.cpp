//
// Created by 郑邦国 on 2018/11/22.
//

#include "Frame.h"

namespace rt {


    Frame* Frame::newFrame(Thread* thread, int maxLocal, int maxStack) {
        LocalVars* local = LocalVars::newLocalVars(maxLocal);
        OperandStack* stack = OperandStack::newOperandStrack(maxStack);
        return new Frame(thread, stack, local);
    }

    LocalVars* Frame::getLocalVars() {
        return localVars;
    }

    OperandStack* Frame::getOperandStack() {
        return operandStack;
    }

    Thread* Frame::getThread() {
        return thread;
    }

    java_int Frame::getNextPc() {
        return nextPC;
    }

    void Frame::setNextPc(java_int _nextPc) {
        nextPC = _nextPc;
    }
}