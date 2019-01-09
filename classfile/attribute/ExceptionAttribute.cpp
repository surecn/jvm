//
// Created by 郑邦国 on 2018/11/22.
//

#include "ExceptionAttribute.h"

namespace cf {

    ExceptionAttribute::~ExceptionAttribute() {
        delete m_exceptionIndexTable;
    }

    void ExceptionAttribute::readInfo(ClassReader *classReader) {
        m_exceptionIndexTable = classReader->readU2s(&m_numberOfException);
    }

}