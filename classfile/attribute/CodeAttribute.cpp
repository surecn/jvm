//
// Created by 郑邦国 on 2018/11/21.
//

#include "CodeAttribute.h"

namespace cf {

    CodeAttribute::~CodeAttribute() {
        delete m_code;
        delete m_exceptionTable;
        delete [] m_attributes;
        delete m_constantPool;
    }

    void CodeAttribute::readInfo(cf::ClassReader *classReader) {
        m_maxStack = classReader->readU2();
        m_maxLocals = classReader->readU2();

        m_codeLength = classReader->readU4();
        m_code = classReader->readU1s(m_codeLength);

        m_exceptionTableLength = classReader->readU2();
        if (m_exceptionTableLength > 0) {
            ExceptionTableEntry::readExceptionTable(classReader, m_exceptionTableLength);
        }
        u2 count = classReader->readU2();
        m_attributes = AttributeInfo::readAttributes(classReader, m_constantPool, count);
    }

    ExceptionTableEntry* ExceptionTableEntry::readExceptionTable(ClassReader *reader, u2 length) {
        ExceptionTableEntry *exceptionTableEntry = (ExceptionTableEntry*)malloc(sizeof(ExceptionTableEntry) * length);
        for (int i = 0; i < length; ++i) {
            exceptionTableEntry[i].read(reader);
        }
        return exceptionTableEntry;
    }

    u1* CodeAttribute::getCode() {
        return m_code;
    }

    u4 CodeAttribute::getCodeLength() {
        return m_codeLength;
    }

    u2 CodeAttribute::getMaxLocals() {
        return m_maxLocals;
    }

    u2 CodeAttribute::getMaxStack() {
        return m_maxStack;
    }




}
