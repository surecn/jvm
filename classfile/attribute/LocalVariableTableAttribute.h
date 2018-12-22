//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_LOCALVARIABLETABLEATTRIBUTE_H
#define JVM_LOCALVARIABLETABLEATTRIBUTE_H

#include "AttributeInfo.h"

namespace cf {
    class LocalVariableTableEntry;

    class LocalVariableTableAttribute : public AttributeInfo{
    private:
        LocalVariableTableEntry **m_localVariableTableEntry;
        int m_length;
    public:
        void readInfo(ClassReader *classReader);
    };

    class LocalVariableTableEntry {
    private:
        int m_startPc;
        int m_length;
        int m_nameIndex;
        int m_descriptorIndex;
        int m_index;
    public:
        LocalVariableTableEntry(ClassReader *classReader);
    };
}


#endif //JVM_LOCALVARIABLETABLEATTRIBUTE_H
