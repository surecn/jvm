//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantNameAndTypeInfo.h"


ConstantInfo* ConstantNameAndTypeInfo::readInfo(ClassReader *classReader) {
    nameIndex = classReader->readU2();
    desciptorIndex = classReader->readU2();
}