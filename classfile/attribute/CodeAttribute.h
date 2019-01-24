//
// Created by 郑邦国 on 2018/11/21.
//

#ifndef JVM_CODEATTRIBUTE_H
#define JVM_CODEATTRIBUTE_H


#include "AttributeInfo.h"
#include "LineNumberAttribute.h"


namespace cf {
    class ExceptionTableEntry;
    class CodeAttribute : public AttributeInfo {
    private:
        //操作数栈的最大深度
        u2 m_maxStack;

        //局部变量表大小
        u2 m_maxLocals;

        //代码字节数
        u4 m_codeLength;

        //字节码
        u1* m_code;

        u2 m_exceptionTableLength;

        ExceptionTableEntry **m_exceptionTable;

        AttributeInfo** m_attributes;

        u2 m_attributeCount;

        ConstantPool *m_constantPool;

    public:
        CodeAttribute(ConstantPool *cp) : m_constantPool(cp) {}
        ~CodeAttribute();
        void readInfo(cf::ClassReader *classReader);
        u2 getMaxStack();
        u2 getMaxLocals();
        u1* getCode();
        u4 getCodeLength();

        ExceptionTableEntry **getExceptionTable() const;
        u2 getExceptionTableLength() const;
        LineNumberTableAttribute * getLineNumberTableAttribute();

    };


    class ExceptionTableEntry {
    private:
        int m_startPc;
        int m_endPc;
        int m_handlerPc;
        int m_catchType;
    public:
        ExceptionTableEntry() {
        }

        void read(ClassReader* classReader) {
            m_startPc = classReader->readU2();
            m_endPc = classReader->readU2();
            m_handlerPc = classReader->readU2();
            m_catchType = classReader->readU2();
        }

        int getStartPc() const;

        int getEndPc() const;

        int getHandlerPc() const;

        int getCatchType() const;


        static ExceptionTableEntry** readExceptionTable(ClassReader *reader, u2 length);
    };

}

#endif //JVM_CODEATTRIBUTE_H
