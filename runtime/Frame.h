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
        LocalVars* m_localVars;
        OperandStack* m_operandStack;
        Thread* m_thread;
        java_int m_nextPC;
    public:
        Frame* lower;
        Frame();
        Frame(Thread* th, int maxLocal, int maxStack);
        ~Frame();
        OperandStack* getOperandStack();
        LocalVars* getLocalVars();
        Thread* getThread();
        java_int getNextPc();
        void setNextPc(java_int _nextPc);
        static Frame* newFrame(Thread* thread, int maxLocal, int maxStack);

    };

}

#endif //JVM_FRAME_H
