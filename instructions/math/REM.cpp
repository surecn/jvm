//
// Created by 郑邦国 on 2018/11/27.
//

#include "REM.h"
#include <math.h>

namespace rt {

    void DREM::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_double v2 = stack->popDouble();
        java_double v1 = stack->popDouble();
        if (v2 == 0) {
            cout << "AritheticException: by zero" << endl;
        }
        java_double result = fmod(v1, v2);
        stack->pushDouble(result);
    }

    void FREM::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_float v2 = stack->popFloat();
        java_float v1 = stack->popFloat();
        if (v2 == 0) {
            cout << "ArithmeticException" << endl;
        }
        java_float result = fmod(v1, v2);
        stack->pushFloat(result);
    }

    void IREM::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int v2 = stack->popInt();
        java_int v1 = stack->popInt();
        if (v2 == 0) {
            cout << "ArithmeticException" << endl;
        }
        java_int result = v1 % v2;
        stack->pushInt(result);
    }

    void LREM::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_long v2 = stack->popLong();
        java_long v1 = stack->popLong();
        if (v2 == 0) {
            cout << "ArithmeticException" << endl;
        }
        java_long result = v1 % v2;
        stack->pushLong(result);
    }

}