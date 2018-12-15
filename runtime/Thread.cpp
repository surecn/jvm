//
// Created by 郑邦国 on 2018/11/22.
//

#include "Thread.h"

namespace rt {

    Thread::Thread() {
        stack = NULL;
    }

    Thread* Thread::newThread() {
        Thread * thread = new Thread();
        thread->stack = Stack::newStack(1024);
        return thread;
    }

    java_int Thread::getPC() {
        return pc;
    }

    void Thread::setPC(java_int val) {
        pc = val;
    }

    void Thread::pushFrame(rt::Frame *frame) {
        stack->push(frame);
    }

    Frame* Thread::popFrame() {
        return stack->pop();
    }

    Frame* Thread::currentFrame() {
        return stack->top();
    }

    Frame* Thread::newFrame(int maxLocals, int maxStack) {
        return Frame::newFrame(this, maxLocals, maxStack);
    }
}