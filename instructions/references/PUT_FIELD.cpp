//
// Created by 郑邦国 on 2018/12/23.
//

#include "PUT_FIELD.h"
#include "../../runtime/heap/ConstantPool.h"
#include "../../runtime/heap/FieldRef.h"

namespace rt {

    void PUT_FIELD::execute(rt::Frame *frame) {
        Method *currentMethod = frame->getMethod();
        Class *currentClass = currentMethod->getClass();
        ConstantPool *cp = currentClass->getConstantPool();
        FieldRef *fieldRef = (FieldRef *)cp->getConstant(m_index);
        Field *field = fieldRef->resolvedField();
        if (field->isStatic()) {
            cout << "java.lang.IncompactibleClassChangeError" << endl;
        }
        if (field->isFinal()) {
            if (currentClass != field->getClass() || *currentMethod->getName() != "<init>") {
                cout << "java.lang.IllegalAccessError" << endl;
            }
        }
        string *descriptor = field->getDescriptor();
        u4 slotId = field->getSlotId();
        OperandStack *stack = frame->getOperandStack();
        switch ((*descriptor)[0]) {
            case 'Z':
            case 'B':
            case 'C':
            case 'S':
            case 'I': {
                java_int val = stack->popInt();
                java_ref ref = stack->popRef();
                if (ref == NULL) {
                    cout << "java.lang.NullPointerException" << endl;
                }
                Object *object = (Object *) ref;
                object->getSlotArray()->setInt(slotId, val);
                break;
            }
            case 'F': {
                java_float val = stack->popFloat();
                java_ref ref = stack->popRef();
                if (ref == NULL) {
                    cout << "java.lang.NullPointerException" << endl;
                }
                Object *object = (Object *) ref;
                object->getSlotArray()->setFloat(slotId, val);
                break;
            }
            case 'J': {
                java_long val = stack->popLong();
                java_ref ref = stack->popRef();
                if (ref == NULL) {
                    cout << "java.lang.NullPointerException" << endl;
                }
                Object *object = (Object *) ref;
                object->getSlotArray()->setLong(slotId, val);
                break;
            }
            case 'D': {
                java_double val = stack->popDouble();
                java_ref ref = stack->popRef();
                if (ref == NULL) {
                    cout << "java.lang.NullPointerException" << endl;
                }
                Object *object = (Object *) ref;
                object->getSlotArray()->setDouble(slotId, val);
                break;
            }
            case 'L': {
                java_ref val = stack->popRef();
                java_ref ref = stack->popRef();
                if (ref == NULL) {
                    cout << "java.lang.NullPointerException" << endl;
                }
                Object *object = (Object *) ref;
                object->getSlotArray()->setRef(slotId, val);
                break;
            }
        }
    }


}