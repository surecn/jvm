//
// Created by 郑邦国 on 2018/11/21.
//

#include "ConstantValueAttribute.h"

namespace cf {

    void ConstantValueAttribute::readInfo(cf::ClassReader *classReader) {
        m_constantValueIndex = classReader->readU2();
    }

}