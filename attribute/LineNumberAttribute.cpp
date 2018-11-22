//
// Created by 郑邦国 on 2018/11/22.
//

#include "LineNumberAttribute.h"


namespace cls {
    void LineNumberTableAttribute::readInfo(ClassReader* classReader) {
        int length = classReader->readU2();

        pLineNumberTableEntry = static_cast<LineNumberTableEntry **>(malloc(sizeof(LineNumberTableEntry*) * length));
        for (int i = 0; i < length; ++i) {
            pLineNumberTableEntry[i] = new LineNumberTableEntry(classReader);
        }
    }

    LineNumberTableEntry::LineNumberTableEntry(ClassReader* classReader) {
        startPc = classReader->readU2();
        lineNumber = classReader->readU2();
    }
}