//
// Created by 郑邦国 on 2018/11/22.
//

#include "SourceFileAttribute.h"

namespace cf {

    SourceFileAttribute::SourceFileAttribute(ConstantPool *cp) : m_constantPool(cp) {

    }

    void SourceFileAttribute::readInfo(ClassReader *reader) {
        int sourceFileIndex = reader->readU2();
        m_sourceFile = m_constantPool->getUtf8(sourceFileIndex);
    }

    string *SourceFileAttribute::getSourceFile() const {
        return m_sourceFile;
    }
}