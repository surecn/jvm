//
// Created by 郑邦国 on 2019/1/21.
//

#ifndef JVM_EXCEPTIONTABLE_H
#define JVM_EXCEPTIONTABLE_H

#include "../../classfile/attribute/CodeAttribute.h"

namespace rt {
    extern class ClassRef;
    extern class Class;
    extern class ConstantPool;

    struct ExceptionHandler {
        int startPC;
        int endPC;
        int handlerPC;
        ClassRef *catchType;
    };

    class ExceptionTable {
    private:
        ExceptionHandler **m_exceptionHandlerList;
        int m_length;
        ClassRef* getCatchRef(int index, rt::ConstantPool* cp);
    public:
        ExceptionTable(cf::ExceptionTableEntry **entries, int length, ConstantPool *cp);
        ExceptionHandler *findExceptionHandler(Class *exClass, int pc);
    };

}


#endif //JVM_EXCEPTIONTABLE_H
