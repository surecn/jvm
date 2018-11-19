//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantUtf8Info.h"

using namespace cls;

ConstantInfo* ConstantUtf8Info::readInfo(ClassReader *classReader) {
    bytes = classReader->readU1s();
    return NULL;
}