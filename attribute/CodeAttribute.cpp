//
// Created by 郑邦国 on 2018/11/21.
//

#include "CodeAttribute.h"

namespace cls {

    CodeAttribute::~CodeAttribute() {
        delete code;
        delete exceptionTable;
        delete [] attributes;
        delete constantPool;
    }

    void CodeAttribute::readInfo(cls::ClassReader *classReader) {
        maxStack = classReader->readU2();
        maxLocals = classReader->readU2();

        codeLength = classReader->readU4();
        code = classReader->readU1s(codeLength);

        exceptionTableLength = classReader->readU2();
        if (exceptionTableLength > 0) {
            ExceptionTableEntry::readExceptionTable(classReader, exceptionTableLength);
        }

        attributes = AttributeInfo::readAttributes(classReader, constantPool);
    }

    ExceptionTableEntry* ExceptionTableEntry::readExceptionTable(ClassReader *reader, u2 length) {
        ExceptionTableEntry *exceptionTableEntry = (ExceptionTableEntry*)malloc(sizeof(ExceptionTableEntry) * length);
        for (int i = 0; i < length; ++i) {
            exceptionTableEntry[i].read(reader);
        }
        return exceptionTableEntry;
    }




}
