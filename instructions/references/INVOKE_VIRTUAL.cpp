//
// Created by 郑邦国 on 2018/12/26.
//

#include "INVOKE_VIRTUAL.h"
#include "../../runtime/heap/ConstantPool.h"
#include "../../runtime/heap/MethodRef.h"

namespace rt {

    void INVOKE_VIRTUAL::execute(rt::Frame *frame) {
        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
        MethodRef *methodRef = (MethodRef*)cp->getConstant(m_index);
        if (*(methodRef->getName()) == "println") {
            OperandStack *stack = frame->getOperandStack();
            if (*(methodRef->getName()) == "(Z)V") {
                cout << stack->popInt() << endl;
            } else if (*(methodRef->getName()) == "(C)V") {
                cout << stack->popInt() << endl;
            } else if (*(methodRef->getName()) == "(C)V") {
                cout << stack->popInt() << endl;
            } else if (*(methodRef->getName()) == "(I)V") {
                cout << stack->popInt() << endl;
            } else if (*(methodRef->getName()) == "(B)V") {
                cout << stack->popInt() << endl;
            } else if (*(methodRef->getName()) == "(S)V") {
                cout << stack->popInt() << endl;
            } else if (*(methodRef->getName()) == "(F)V") {
                cout << stack->popFloat() << endl;
            } else if (*(methodRef->getName()) == "(J)V") {
                cout << stack->popLong() << endl;
            } else if (*(methodRef->getName()) == "(D)V") {
                cout << stack->popDouble() << endl;
            } else {
                cout << "println: " << *methodRef->getDescriptor() << endl;
            }
            stack->popRef();
        }
    }

}