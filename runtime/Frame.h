//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_FRAME_H
#define JVM_FRAME_H

#include "../common.h"
#include "OperandStack.h"
#include "LocalVars.h"

namespace rt {
    class Frame {
    private:
        LocalVars* localVars;
        OperandStack* operandStack;
    public:
        Frame* lower;
        Frame();
        OperandStack* getOperandStack();
        LocalVars* getLocalVars();
        static Frame* newFrame(int maxLocal, int maxStack);
    };

}

#endif //JVM_FRAME_H
