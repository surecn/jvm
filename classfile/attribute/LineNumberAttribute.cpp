//
// Created by 郑邦国 on 2018/11/22.
//

#include "LineNumberAttribute.h"


namespace cf {
    void LineNumberTableAttribute::readInfo(ClassReader* classReader) {
        m_lineNumberCount = classReader->readU2();

        m_lineNumberTableEntry = static_cast<LineNumberTableEntry **>(malloc(sizeof(LineNumberTableEntry*) * m_lineNumberCount));
        for (int i = 0; i < m_lineNumberCount; ++i) {
            m_lineNumberTableEntry[i] = new LineNumberTableEntry(classReader);
        }
    }

    int LineNumberTableAttribute::getLineNumber(int pc) {
        for (int i = m_lineNumberCount - 1; i >= 0 ; --i) {
            LineNumberTableEntry *lineNumberTableEntry = m_lineNumberTableEntry[i];
            if (lineNumberTableEntry->getStartPc() <= pc) {
                return lineNumberTableEntry->getLineNumber();
            }
        }
        return -1;
    }

    LineNumberTableEntry::LineNumberTableEntry(ClassReader* classReader) {
        m_startPc = classReader->readU2();
        m_lineNumber = classReader->readU2();
    }

    u2 LineNumberTableEntry::getStartPc() const {
        return m_startPc;
    }

    u2 LineNumberTableEntry::getLineNumber() const {
        return m_lineNumber;
    }
}