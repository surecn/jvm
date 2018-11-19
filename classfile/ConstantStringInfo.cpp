//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantStringInfo.h"

using namespace cls;

ConstantInfo* ConstantStringInfo::readInfo(ClassReader *classReader) {
    stringIndex = classReader->readU2();
}

string ConstantStringInfo::toString() {

    constantPool->getUtf8(stringIndex);
    return NULL;
}