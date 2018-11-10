//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantFieldRefInfo.h"


ConstantInfo* ConstantFieldRefInfo::readInfo(ClassReader *classReader) {
    classIndex = classReader->readU2();
    nameAndTypeIndex = classReader->readU2();
}