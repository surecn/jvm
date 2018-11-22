//
// Created by 郑邦国 on 2018/11/22.
//

#include "SourceFileAttribute.h"

namespace cls {

    SourceFileAttribute::SourceFileAttribute(ConstantPool *cp) : constantPool(cp) {

    }

    void SourceFileAttribute::readInfo(cls::ClassReader *reader) {
        int sourceFileIndex = reader->readU2();
        sourceFile = constantPool->getUtf8(sourceFileIndex);
    }
}