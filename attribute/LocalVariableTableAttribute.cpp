//
// Created by 郑邦国 on 2018/11/22.
//

#include "LocalVariableTableAttribute.h"

namespace cls {

    void LocalVariableTableAttribute::readInfo(cls::ClassReader *classReader) {
        length = classReader->readU2();
        localVariableTableEntry = static_cast<LocalVariableTableEntry **>(malloc(sizeof(LocalVariableTableEntry*) * length));
        for (int i = 0; i < length; ++i) {
            localVariableTableEntry[i] = new LocalVariableTableEntry(classReader);
        }
    }

    LocalVariableTableEntry::LocalVariableTableEntry(cls::ClassReader *classReader) {
        startPc = classReader->readU2();
        length = classReader->readU2();
        nameIndex = classReader->readU2();
        descriptorIndex = classReader->readU2();
        index = classReader->readU2();
    }

}
