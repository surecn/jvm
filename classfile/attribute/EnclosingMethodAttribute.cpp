//
// Created by 郑邦国 on 2018/12/25.
//

#include "EnclosingMethodAttribute.h"

namespace cf {

    void EnclosingMethodAttribute::readInfo(cf::ClassReader *classReader) {
        m_classIndex = classReader->readU2();
        m_methodIndex = classReader->readU2();
    }

    string* EnclosingMethodAttribute::getClassName() {
        return m_cp->getClassName(m_classIndex);
    }

    NameAndType EnclosingMethodAttribute::getNameAndDescriptor() {
        if (m_methodIndex > 0) {
            return m_cp->getNameAndType(m_methodIndex);
        }
        return NameAndType();
    }

}