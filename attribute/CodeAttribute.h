//
// Created by 郑邦国 on 2018/11/21.
//

#ifndef JVM_CODEATTRIBUTE_H
#define JVM_CODEATTRIBUTE_H


#include "AttributeInfo.h"

namespace cls {
    class ExceptionTableEntry;
    class CodeAttribute : public AttributeInfo {
    private:
        //操作数栈的最大深度
        u2 maxStack;

        //局部变量表大小
        u2 maxLocals;

        //代码字节数
        u4 codeLength;

        //字节码
        u1* code;

        u2 exceptionTableLength;
        ExceptionTableEntry *exceptionTable;

        AttributeInfo** attributes;

        ConstantPool *constantPool;

    public:
        CodeAttribute(ConstantPool *cp) : constantPool(cp) {}
        ~CodeAttribute();
        void readInfo(cls::ClassReader *classReader);
        u2 getMaxStack();
        u2 getMaxLocals();
        u1* getCode();
        u4 getCodeLength();

    };


    class ExceptionTableEntry {
    private:
        int startPc;
        int endPc;
        int handlerPc;
        int catchType;
    public:
        ExceptionTableEntry() {
        }

        void read(ClassReader* classReader) {
            startPc = classReader->readU2();
            endPc = classReader->readU2();
            handlerPc = classReader->readU2();
            catchType = classReader->readU2();
        }

        static ExceptionTableEntry* readExceptionTable(ClassReader *reader, u2 length);
    };

}

#endif //JVM_CODEATTRIBUTE_H
