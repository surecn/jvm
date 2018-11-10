//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantUtf8Info.h"

ConstantInfo* ConstantUtf8Info::readInfo(ClassReader *classReader) {
    length = classReader->readU4();
    bytes = classReader->readU1s(length);
}