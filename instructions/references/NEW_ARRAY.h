//
// Created by 郑邦国 on 2019/1/4.
//

#ifndef JVM_NEW_ARRAY_H
#define JVM_NEW_ARRAY_H


#include "../../common.h"
#include "../base/Instruction.h"
#include "../../runtime/heap/ClassLoader.h"
#include "../../runtime/heap/ArrayClass.h"

namespace rt {

    const java_char AT_BOOLEAN = 4;
    const java_char AT_CHAR = 5;
    const java_char AT_FLOAT = 6;
    const java_char AT_DOUBLE = 7;
    const java_char AT_BYTE = 8;
    const java_char AT_SHORT = 9;
    const java_char AT_INT = 10;
    const java_char AT_LONG = 11;

    class NEW_ARRAY : public Instruction {
    private:
        java_char atype;
        Class* getPrimitiveArrayClass(ClassLoader *loader, java_char atype);
    public:
        void fetchOperand(BytecodeReader* reader);
        void execute(Frame* frame);
    };

}


#endif //JVM_NEW_ARRAY_H
