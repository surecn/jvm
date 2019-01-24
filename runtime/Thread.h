//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_THREAD_H
#define JVM_THREAD_H


#include "Stack.h"

namespace rt {
    extern class Method;
    class Thread {
    private:
        java_int m_pc;
        Stack *m_stack;
    public:
        Thread();
        java_int getPC();
        void setPC(java_int val);
        void pushFrame(Frame* frame);
        Frame* popFrame();
        Frame* currentFrame();
        Frame* topFrame();
        Frame* newFrame(Method *method);
        bool isStackEmpty();
        void clearStack();
        Stack* getFrames();
        static Thread *newThread();
    };

}


#endif //JVM_THREAD_H
