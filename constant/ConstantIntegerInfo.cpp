//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantIntegerInfo.h"

ConstantInfo* ConstantIntegerInfo::readInfo(ClassReader *classReader) {
    value = classReader->readU4();
}