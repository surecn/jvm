//
// Created by 郑邦国 on 2018/12/6.
//

#include "IF_ACMP.h"

namespace rt {

    void IF_ACMPEQ::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_ref ref2 = stack->popRef();
        java_ref ref1 = stack->popRef();
        if (ref1 == ref2) {
            branch(frame, _offset);
        }
    }

    void IF_ACMPNE::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_ref ref2 = stack->popRef();
        java_ref ref1 = stack->popRef();
        if (ref1 != ref2) {
            branch(frame, _offset);
        }
    }

}