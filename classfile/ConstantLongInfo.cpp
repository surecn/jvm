//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantLongInfo.h"

using namespace cls;

ConstantInfo* ConstantLongInfo::readInfo(ClassReader *classReader) {
    value = classReader->readU8();
    return NULL;
}