//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantDoubleInfo.h"

using namespace cls;

ConstantInfo* ConstantDoubleInfo::readInfo(ClassReader * classReader) {
    value = classReader->readU8();
}