//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantMemberInfo.h"


ConstantInfo* ConstantMemberInfo::readInfo(ClassReader *classReader) {
    classIndex = classReader->readU2();
    nameAndTypeIndex = classReader->readU2();
}