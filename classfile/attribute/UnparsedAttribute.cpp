//
// Created by 郑邦国 on 2018/11/22.
//

#include "UnparsedAttribute.h"

namespace cf {

    void UnparsedAttribute::readInfo(ClassReader *classReader) {
        m_info = classReader->readU1s(m_length);
    }

}
