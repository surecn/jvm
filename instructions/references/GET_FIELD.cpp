//
// Created by 郑邦国 on 2018/12/23.
//

#include "GET_FIELD.h"
#include "../../runtime/heap/ConstantPool.h"
#include "../../runtime/heap/FieldRef.h"

namespace rt {

    void GET_FIELD::execute(rt::Frame *frame) {
        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
        FieldRef *fieldRef = cp->getFieldRef(m_index);
        cout << "GET_FIELD :" << *fieldRef->getName() << endl;
        Field *field = fieldRef->resolvedField();
        if (field->isStatic()) {
            cout << "java.lang.IncompatibleClassChangeError" << endl;
        }
        OperandStack *stack = frame->getOperandStack();
        java_ref ref = stack->popRef();
        if (ref == NULL) {
            cout << "java.lang.NullPointerException" << endl;
        }
        string *descriptor = field->getDescriptor();
        u4 slotId = field->getSlotId();
        Object *object = (Object *)ref;
        SlotArray *slotArray = object->getFields();
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
            case '[':
            case 'L':
                stack->pushRef(slotArray->getRef(slotId));
                break;
        }
    }

}
