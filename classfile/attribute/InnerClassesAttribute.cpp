//
// Created by 郑邦国 on 2018/12/25.
//

#include "InnerClassesAttribute.h"

namespace cf {

    void InnerClassesAttribute::readInfo(cf::ClassReader *classReader) {
        m_classesCount = classReader->readU2();
        m_classes = new InnerClassInfo*[m_classesCount];
        for (int i = 0; i < m_classesCount; ++i) {
            m_classes[i] = new InnerClassInfo();
            m_classes[i]->innerClassInfoIndex = classReader->readU2();
            m_classes[i]->outerClassInfoIndex = classReader->readU2();
            m_classes[i]->innerNameIndex = classReader->readU2();
            m_classes[i]->innerClassAccessFlags = classReader->readU2();
        }
    }

}