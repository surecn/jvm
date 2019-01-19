//
// Created by 郑邦国 on 2018/12/23.
//

#include "GET_STATIC.h"
#include "../../runtime/heap/Class.h"
#include "../../runtime/heap/FieldRef.h"
#include "../../runtime/heap/ConstantPool.h"

namespace rt {

    void GET_STATIC::execute(rt::Frame *frame) {
        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
        FieldRef *fieldRef = cp->getFieldRef(m_index);
        Field *field = fieldRef->resolvedField();
        Class *cls = field->getClass();
        if (!cls->isInitStarted()) {
            frame->revertNextPC();
            cls->initClass(frame->getThread());
            return;
        }
        if (!field->isStatic()) {
            cout << "java.lang.IncompatibleClassChangeError" << endl;
        }
        string *descriptor = field->getDescriptor();
        u4 slotId = field->getSlotId();
        SlotArray *slotArray = cls->getStaticVars();
        OperandStack *stack = frame->getOperandStack();
        switch ((*descriptor)[0]) {
            case 'Z':
            case 'B':
            case 'C':
            case 'S':
            case 'I':
                stack->pushInt(slotArray->getInt(slotId));
                break;
            case 'F':
                stack->pushFloat(slotArray->getFloat(slotId));
                break;
            case 'J':
                stack->pushLong(slotArray->getLong(slotId));
                break;
            case 'D':
                stack->pushDouble(slotArray->getDouble(slotId));
                break;
            case 'L':
            case '[':
                stack->pushRef(slotArray->getRef(slotId));
                break;
        }
    }


}