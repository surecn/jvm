//
// Created by 郑邦国 on 2018/11/21.
//

#include "ConstantValueAttribute.h"

namespace cls {

    void ConstantValueAttribute::readInfo(cls::ClassReader *classReader) {
        constantValueIndex = classReader->readU2();
    }

}