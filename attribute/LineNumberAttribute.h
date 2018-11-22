//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_LINENUMBERATTRIBUTE_H
#define JVM_LINENUMBERATTRIBUTE_H


#include "../classfile/ClassReader.h"
#include "AttributeInfo.h"

namespace cls {

    class LineNumberTableEntry;

    class LineNumberTableAttribute : public AttributeInfo {
    private:
        LineNumberTableEntry **pLineNumberTableEntry;

    public:
        void readInfo(ClassReader *classReader);
    };

    class LineNumberTableEntry {
    private:
        u2 startPc;
        u2 lineNumber;
    public:
        LineNumberTableEntry(ClassReader *classReader);
    };
}


#endif //JVM_LINENUMBERATTRIBUTE_H
