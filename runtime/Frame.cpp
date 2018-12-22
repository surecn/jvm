//
// Created by 郑邦国 on 2018/11/22.
//

#include "Frame.h"

namespace rt {

    Frame::Frame() {
        m_nextPC = 0L;
    }

    Frame::Frame(Thread* th, int maxLocal, int maxStack) : m_thread(th), m_operandStack(new OperandStack(maxStack)), m_localVars(new LocalVars(maxLocal)) {
        m_nextPC = 0L;
        cout << "frame" << this << "=====" << m_localVars << endl;
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
}