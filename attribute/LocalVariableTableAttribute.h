//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_LOCALVARIABLETABLEATTRIBUTE_H
#define JVM_LOCALVARIABLETABLEATTRIBUTE_H

#include "AttributeInfo.h"

namespace cls {
    class LocalVariableTableEntry;

    class LocalVariableTableAttribute : public AttributeInfo{
    private:
        LocalVariableTableEntry **localVariableTableEntry;
        int length;
    public:
        void readInfo(ClassReader *classReader);
    };

    class LocalVariableTableEntry {
    private:
        int startPc;
        int length;
        int nameIndex;
        int descriptorIndex;
        int index;
    public:
        LocalVariableTableEntry(ClassReader *classReader);
    };
}


#endif //JVM_LOCALVARIABLETABLEATTRIBUTE_H
