//
// Created by 郑邦国 on 2018/12/23.
//

#include "LDC.h"
#include "../../runtime/heap/ConstantPool.h"
#include "../../runtime/heap/StringPool.h"
#include "../../runtime/heap/ClassRef.h"

namespace rt {

    void _ldc(Frame *frame, u4 index) {
        OperandStack *stack = frame->getOperandStack();
        Class *cls = frame->getMethod()->getClass();
        ConstantPool *cp = cls->getConstantPool();
        Constant* constant = cp->getConstant(index);

        switch (constant->type) {
            case CONSTANT_Integer: {
                ConstantInteger *constantInteger = (ConstantInteger *) constant;
                stack->pushInt((java_int) constantInteger->value);
                break;
            }
            case CONSTANT_FLoat: {
                ConstantFloat *constantFloat = (ConstantFloat *) constant;
                stack->pushFloat((java_float) constantFloat->value);
                break;
            }
            case CONSTANT_String: {
                ConstantString *constantString = (ConstantString *) constant;
                Object *obj = StringPool::getJString(cls->getClassLoader(), constantString->value);
                stack->pushRef(obj);
                break;
            }
            case CONSTANT_Class: {
                ConstantClassRef *constantClassRef = (ConstantClassRef *) constant;
                stack->pushRef(constantClassRef->ref->resolvedClass()->getJClass());
                break;
            }
            default:
                cout << "todo: ldc!" << typeid(*constant).name() << endl;
                break;
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
        Constant* constant = cp->getConstant(m_index);
        switch (constant->type) {
            case CONSTANT_Long: {
                ConstantLong *constantLong = (ConstantLong *) constant;
                stack->pushLong(constantLong->value);
                break;
            }
            case CONSTANT_Double: {
                ConstantDouble *constantDouble = (ConstantDouble *) constant;
                stack->pushDouble((java_double) constantDouble->value);
                break;
            }
            default:
                cout << "java.lang.ClassFormatError" << endl;
                break;
        }
    }

}