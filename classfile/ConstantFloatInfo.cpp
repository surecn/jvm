//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantFloatInfo.h"

using namespace cls;

ConstantInfo* ConstantFloatInfo::readInfo(ClassReader *classReader) {
    value = classReader->readU4();
    return NULL;
}