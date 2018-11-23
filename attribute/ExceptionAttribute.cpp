//
// Created by 郑邦国 on 2018/11/22.
//

#include "ExceptionAttribute.h"

namespace cls {

    ExceptionAttribute::~ExceptionAttribute() {
        delete exceptionIndexTable;
    }

    void ExceptionAttribute::readInfo(cls::ClassReader *classReader) {
        exceptionIndexTable = classReader->readU2s(numberOfException);
    }

}