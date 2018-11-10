//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantMethodInfo.h"


ConstantInfo* ConstantMethodInfo::readInfo(ClassReader *classReader) {
    classIndex = classReader->readU2();
    nameAndTypeIndex = classReader->readU2();
}