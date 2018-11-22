//
// Created by 郑邦国 on 2018/11/22.
//

#include "UnparsedAttribute.h"

namespace cls {

    void UnparsedAttribute::readInfo(cls::ClassReader *classReader) {
        info = classReader->readU1s(length);
    }

}
