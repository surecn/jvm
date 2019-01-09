//
// Created by 郑邦国 on 2018/12/23.
//

#include "LDC.h"
#include "../../runtime/heap/ConstantPool.h"

namespace rt {

    void _ldc(Frame *frame, u4 index) {
        OperandStack *stack = frame->getOperandStack();
        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
        Constant constant = cp->getConstant(index);
        string name = typeid(*constant).name();
        if (name == typeid(java_int).name()) {
            stack->pushInt(*((java_int *)constant));
        } else if (name == typeid(java_float).name()) {
            stack->pushFloat(*((java_float *)constant));
        } else {
            cout << "todo: ldc!" << endl;
        }

    }

    void LDC::execute(rt::Frame *frame) {
        _ldc(frame, m_index);
    }

    void LDC_W::execute(rt::Frame *frame) {
        _ldc(frame, m_index);
    }

    void LDC2_W::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
        Constant constant = cp->getConstant(m_index);
        string name = typeid(*constant).name();
        if (name == typeid(java_long).name()) {
            stack->pushLong(*((java_long *)constant));
        } else if (name == typeid(java_double).name()) {
            stack->pushDouble(*((java_double *)constant));
        } else {
            cout << "java.lang.ClassFormatError" << endl;
        }
    }

}