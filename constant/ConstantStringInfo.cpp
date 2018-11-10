//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantStringInfo.h"

ConstantInfo* ConstantStringInfo::readInfo(ClassReader *classReader) {
    stringIndex = classReader->readU2();
}

string ConstantStringInfo::toString() {
    constantPool->getUtf8(stringIndex);
}