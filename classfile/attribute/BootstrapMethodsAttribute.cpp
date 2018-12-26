//
// Created by 郑邦国 on 2018/12/25.
//

#include "BootstrapMethodsAttribute.h"

namespace cf {

    void BootstrapMethodsAttribute::readInfo(ClassReader* classReader) {
        u2 numBootstrapMethods = classReader->readU2();
        m_bootstrapMethod = new BootstrapMethod*[numBootstrapMethods];
        for (int i = 0; i < numBootstrapMethods; ++i) {
            m_bootstrapMethod[i] = new BootstrapMethod();
            m_bootstrapMethod[i]->bootstrapMethodRef = classReader->readU2();
            m_bootstrapMethod[i]->bootstrapArguments = classReader->readU2s(&m_bootstrapMethod[i]->bootstrapArgumentSize);
        }
    }

}