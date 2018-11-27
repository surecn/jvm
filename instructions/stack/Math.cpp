//
// Created by 郑邦国 on 2018/11/27.
//

#include "Math.h"
#include <math.h>

namespace rt {

    void DRem::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_double v2 = stack->popDouble();
        java_double v1 = stack->popInt();
        if (v2 == 0) {
            cout << "AritheticException: by zero" << endl;
        }
        java_double result = fmod(v1, v2);
        stack->pushDouble(result);
    }

    void FRem::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        float v2 = stack->popFloat();
        float v1 = stack->popFloat();
        if (v2 == 0) {
            cout << "ArithmeticException" << endl;
        }
        float result = fmod(v1, v2);
        stack->pushFloat(result);
    }

    void IRem::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        int v2 = stack->popFloat();
        int v1 = stack->popFloat();
        if (v2 == 0) {
            cout << "ArithmeticException" << endl;
        }
        int result = v1 % v2;
        stack->pushInt(result);
    }

    void LRem::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        long v2 = stack->popFloat();
        long v1 = stack->popFloat();
        if (v2 == 0) {
            cout << "ArithmeticException" << endl;
        }
        long result = v1 % v2;
        stack->pushInt(result);
    }

}