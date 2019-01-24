//
// Created by 郑邦国 on 2019/1/23.
//

#include "JUnsafe.h"
#include "../../Registry.h"

namespace native {

    void JUnsafe::init() {
        string clsName("sun/misc/Unsafe");
        Registry::registerNative(clsName, "arrayBaseOffset", "(Ljava/lang/Class;)I", &JUnsafe::arrayBaseOffset);
        Registry::registerNative(clsName, "arrayIndexScale", "(Ljava/lang/Class;)I", &JUnsafe::arrayIndexScale);
        Registry::registerNative(clsName, "addressSize", "()I", &JUnsafe::addressSize);
    }

    void JUnsafe::arrayBaseOffset(rt::Frame *frame) {
        rt::OperandStack *stack = frame->getOperandStack();
        stack->pushInt(0);
    }

    void JUnsafe::arrayIndexScale(rt::Frame *frame) {
        rt::OperandStack *stack = frame->getOperandStack();
        stack->pushInt(1);
    }

    void JUnsafe::addressSize(rt::Frame *frame) {
        rt::OperandStack *stack = frame->getOperandStack();
        stack->pushInt(8);
    }

}