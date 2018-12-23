//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_FRAME_H
#define JVM_FRAME_H

#include "OperandStack.h"
#include "LocalVars.h"
#include "heap/Method.h"


namespace rt {
    extern class Thread;
    class Frame {
    private:
        LocalVars* m_localVars;
        OperandStack* m_operandStack;
        Thread* m_thread;
        java_int m_nextPC;
        Method *m_method;
    public:
        Frame* lower;
        Frame();
        Frame(Thread* th, Method *method);
        ~Frame();
        OperandStack* getOperandStack();
        LocalVars* getLocalVars();
        Thread* getThread();
        java_int getNextPc();
        void setNextPc(java_int _nextPc);
        Method *getMethod() const;
    };

}

#endif //JVM_FRAME_H
