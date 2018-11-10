//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantClassInfo.h"


ConstantInfo* ConstantClassInfo::readInfo(ClassReader *classReader) {
    nameIndex = classReader->readU2();
}

string* ConstantClassInfo::getName() {
    constantPool.getClassName(nameIndex);
}