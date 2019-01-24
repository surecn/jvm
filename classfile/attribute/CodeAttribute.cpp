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
            m_exceptionTable = ExceptionTableEntry::readExceptionTable(classReader, m_exceptionTableLength);
        }
        m_attributes = AttributeInfo::readAttributes(classReader, m_constantPool, &m_attributeCount);
    }

    ExceptionTableEntry **CodeAttribute::getExceptionTable() const {
        return m_exceptionTable;
    }

    u2 CodeAttribute::getExceptionTableLength() const {
        return m_exceptionTableLength;
    }

    LineNumberTableAttribute * CodeAttribute::getLineNumberTableAttribute() {
        for (int i = 0; i < m_attributeCount; ++i) {
            AttributeInfo* attributeInfo = m_attributes[i];
            if (attributeInfo->getAttributeType() == "LineNumberTable") {
                return (LineNumberTableAttribute*)attributeInfo;
            }
        }
        return NULL;
    }

    ExceptionTableEntry** ExceptionTableEntry::readExceptionTable(ClassReader *reader, u2 length) {
        ExceptionTableEntry **exceptionTableEntry = (ExceptionTableEntry**)malloc(sizeof(ExceptionTableEntry) * length);
        for (int i = 0; i < length; ++i) {
            exceptionTableEntry[i] = new ExceptionTableEntry();
            exceptionTableEntry[i]->read(reader);
        }
        return exceptionTableEntry;
    }

    int ExceptionTableEntry::getStartPc() const {
        return m_startPc;
    }

    int ExceptionTableEntry::getEndPc() const {
        return m_endPc;
    }

    int ExceptionTableEntry::getHandlerPc() const {
        return m_handlerPc;
    }

    int ExceptionTableEntry::getCatchType() const {
        return m_catchType;
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
