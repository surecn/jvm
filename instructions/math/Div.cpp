//
// Created by 郑邦国 on 2018/12/12.
//

#include "Div.h"

namespace rt {

    void IDIV::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int val1 = stack->popInt();
        java_int val2 = stack->popInt();
        if (val2 == 0) {
            cout << "java.lang.ArithmeticException: / by zero" << endl;
        }
        stack->pushInt(val1 / val2);
    }

    void LDIV::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_long val1 = stack->popLong();
        java_long val2 = stack->popLong();
        if (val2 == 0) {
            cout << "java.lang.ArithmeticException: / by zero" << endl;
        }
        stack->pushLong(val1 / val2);
    }

    void FDIV::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_float val1 = stack->popFloat();
        java_float val2 = stack->popFloat();
        stack->pushFloat(val1 / val2);
    }

    void DDIV::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_double val1 = stack->popDouble();
        java_double val2 = stack->popDouble();
        stack->pushDouble(val1 / val2);
    }

}