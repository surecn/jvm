//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_LINENUMBERATTRIBUTE_H
#define JVM_LINENUMBERATTRIBUTE_H


#include "../ClassReader.h"
#include "AttributeInfo.h"

namespace cf {

    class LineNumberTableEntry;

    class LineNumberTableAttribute : public AttributeInfo {
    private:
        LineNumberTableEntry **m_lineNumberTableEntry;
        int m_lineNumberCount;

    public:
        void readInfo(ClassReader *classReader);
        int getLineNumber(int pc);
    };

    class LineNumberTableEntry {
    private:
        u2 m_startPc;
        u2 m_lineNumber;
    public:
        LineNumberTableEntry(ClassReader *classReader);

        u2 getStartPc() const;

        u2 getLineNumber() const;
    };
}


#endif //JVM_LINENUMBERATTRIBUTE_H
