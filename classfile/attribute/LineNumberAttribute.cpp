//
// Created by 郑邦国 on 2018/11/22.
//

#include "LineNumberAttribute.h"


namespace cf {
    void LineNumberTableAttribute::readInfo(ClassReader* classReader) {
        int length = classReader->readU2();

        m_pLineNumberTableEntry = static_cast<LineNumberTableEntry **>(malloc(sizeof(LineNumberTableEntry*) * length));
        for (int i = 0; i < length; ++i) {
            m_pLineNumberTableEntry[i] = new LineNumberTableEntry(classReader);
        }
    }

    LineNumberTableEntry::LineNumberTableEntry(ClassReader* classReader) {
        m_startPc = classReader->readU2();
        m_lineNumber = classReader->readU2();
    }
}