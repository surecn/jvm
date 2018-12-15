//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_FRAME_H
#define JVM_FRAME_H

#include "OperandStack.h"
#include "LocalVars.h"


namespace rt {
    extern class Thread;
    class Frame {
    private:
        LocalVars* localVars;
        OperandStack* operandStack;
        Thread* thread;
        java_int nextPC;
    public:
        Frame* lower;
        Frame() {}
        Frame(Thread* th, OperandStack* stack, LocalVars* vars) : thread(th), operandStack(stack), localVars(vars) {}
        OperandStack* getOperandStack();
        LocalVars* getLocalVars();
        Thread* getThread();
        java_int getNextPc();
        void setNextPc(java_int _nextPc);
        static Frame* newFrame(Thread* thread, int maxLocal, int maxStack);
    };

}

#endif //JVM_FRAME_H
