//
// Created by 郑邦国 on 2018/11/22.
//

#include "Frame.h"
#include "Thread.h"

namespace rt {

    Frame::Frame() {
        m_nextPC = 0L;
        m_lower = NULL;
    }

    Frame::Frame(Thread* th, Method *method) : m_method(method), m_thread(th), m_operandStack(new OperandStack(method->getMaxStack(), *method->getName())), m_localVars(new LocalVars(method->getMaxLocals())) {
        m_nextPC = 0L;
        m_lower = NULL;
    }

    Frame::~Frame() {
        if (m_operandStack != NULL) {
            delete m_operandStack;
        }
        if (m_localVars != NULL) {
            delete m_localVars;
        }
    }

    LocalVars* Frame::getLocalVars() {
        return m_localVars;
    }

    OperandStack* Frame::getOperandStack() {
        return m_operandStack;
    }

    Thread* Frame::getThread() {
        return m_thread;
    }

    java_int Frame::getNextPc() {
        return m_nextPC;
    }

    void Frame::setNextPc(java_int _nextPc) {
        m_nextPC = _nextPc;
    }

    Method *Frame::getMethod() const {
        return m_method;
    }

    void Frame::revertNextPC() {
        m_nextPC = m_thread->getPC();
    }
}