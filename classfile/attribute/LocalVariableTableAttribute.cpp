//
// Created by 郑邦国 on 2018/11/22.
//

#include "LocalVariableTableAttribute.h"

namespace cf {

    void LocalVariableTableAttribute::readInfo(ClassReader *classReader) {
        m_length = classReader->readU2();
        m_localVariableTableEntry = static_cast<LocalVariableTableEntry **>(malloc(sizeof(LocalVariableTableEntry*) * m_length));
        for (int i = 0; i < m_length; ++i) {
            m_localVariableTableEntry[i] = new LocalVariableTableEntry(classReader);
        }
    }

    LocalVariableTableEntry::LocalVariableTableEntry(ClassReader *classReader) {
        m_startPc = classReader->readU2();
        m_length = classReader->readU2();
        m_nameIndex = classReader->readU2();
        m_descriptorIndex = classReader->readU2();
        m_index = classReader->readU2();
    }

}
