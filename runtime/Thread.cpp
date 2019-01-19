//
// Created by 郑邦国 on 2018/11/22.
//

#include "Thread.h"

namespace rt {

    Thread::Thread() {
        m_stack = NULL;
    }

    Thread* Thread::newThread() {
        Thread * thread = new Thread();
        thread->m_stack = Stack::newStack(1024);
        return thread;
    }

    java_int Thread::getPC() {
        return m_pc;
    }

    void Thread::setPC(java_int val) {
        m_pc = val;
    }

    void Thread::pushFrame(rt::Frame *frame) {
        m_stack->push(frame);
    }

    Frame* Thread::popFrame() {
        return m_stack->pop();
    }

    Frame* Thread::currentFrame() {
        return m_stack->top();
    }

    Frame* Thread::topFrame() {
        return m_stack->top();
    }

    bool Thread::isStackEmpty() {
        return m_stack->isEmpty();
    }

    Frame* Thread::newFrame(Method *method) {
        return new Frame(this, method);
    }
}