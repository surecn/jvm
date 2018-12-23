//
// Created by 郑邦国 on 2018/12/6.
//

#include "IF_ICMP.h"

namespace rt {

    void IF_ICMPEQ::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        int val2 = stack->popInt();
        int val1 = stack->popInt();
        if (val1 == val2) {
            branch(frame, m_offset);
        }
    }

    void IF_ICMPNE::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        int val2 = stack->popInt();
        int val1 = stack->popInt();
        if (val1 != val2) {
            branch(frame, m_offset);
        }
    }

    void IF_ICMPLT::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        int val2 = stack->popInt();
        int val1 = stack->popInt();
        if (val1 < val2) {
            branch(frame, m_offset);
        }
    }

    void IF_ICMPLE::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        int val2 = stack->popInt();
        int val1 = stack->popInt();
        if (val1 <= val2) {
            branch(frame, m_offset);
        }
    }

    void IF_ICMPGT::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        int val2 = stack->popInt();
        int val1 = stack->popInt();
        if (val1 > val2) {
            branch(frame, m_offset);
        }
    }

    void IF_ICMPGE::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        int val2 = stack->popInt();
        int val1 = stack->popInt();
        if (val1 >= val2) {
            branch(frame, m_offset);
        }
    }

}