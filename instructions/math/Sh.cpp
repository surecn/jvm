//
// Created by 郑邦国 on 2018/11/30.
//

#include "Sh.h"

namespace rt {

    void ISHL::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int v2 = stack->popInt();
        java_int v1 = stack->popInt();
        java_int s = uint(v2) & 0x1f;
        java_int result = v1 << s;
        stack->pushInt(result);
    }

    void ISHR::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int v2 = stack->popInt();
        java_int v1 = stack->popInt();
        java_int s = uint(v2) & 0x1f;
        java_int result = v1 >> s;
        stack->pushInt(result);
    }

    void IUSHR::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int v2 = stack->popInt();
        java_int v1 = stack->popInt();
        java_int s = java_int(v2) & 0x1f;
        java_int result = u4(v1) >> s;
        stack->pushInt(result);
    }

    void LSHL::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int v2 = stack->popInt();
        java_long v1 = stack->popLong();
        java_int s = uint(v2) & 0x3f;
        java_long result = v1 << s;
        stack->pushLong(result);
    }

    void LSHR::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int v2 = stack->popInt();
        java_long v1 = stack->popLong();
        java_int s = uint(v2) & 0x3f;
        java_long result = v1 >> s;
        stack->pushLong(result);
    }

    void LUSHR::execute(rt::Frame *frame) {
        OperandStack* stack = frame->getOperandStack();
        java_int v2 = stack->popInt();
        java_long v1 = stack->popLong();
        java_int s = java_int(v2) & 0x3f;
        java_long result = u4(v1) >> s;
        stack->pushLong(result);
    }

}
