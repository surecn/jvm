//
// Created by 郑邦国 on 2018/12/23.
//

#include "PUT_STATIC.h"
#include "../../runtime/heap/ConstantPool.h"
#include "../../runtime/heap/FieldRef.h"

namespace rt {

    void PUT_STATIC::execute(rt::Frame *frame) {
        Method *currentMethod = frame->getMethod();
        Class *currentClass = currentMethod->getClass();
        ConstantPool *cp = currentClass->getConstantPool();
        FieldRef *fieldRef = (FieldRef *)cp->getConstant(m_index);
        Field *field = fieldRef->resolvedField();
        Class *cls = field->getClass();
        if (!field->isStatic()) {
            cout << "java.lang.IncompatibleClassChangeError" << endl;
        }
        if (field->isFinal()) {
            if (currentClass != cls || *currentMethod->getName() != "<clinit>") {
                cout << "java.lang.IllegalAccessError" << endl;
            }
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
                slotArray->setInt(slotId, stack->popInt());
                break;
            case 'F':
                slotArray->setFloat(slotId, stack->popFloat());
                break;
            case 'J':
                slotArray->setLong(slotId, stack->popLong());
                break;
            case 'D':
                slotArray->setDouble(slotId, stack->popDouble());
                break;
            case 'L':
                slotArray->setRef(slotId, stack->popRef());
                break;
        }
    }

}