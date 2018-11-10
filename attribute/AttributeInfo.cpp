//
// Created by 郑邦国 on 2018/11/10.
//

#include "AttributeInfo.h"


void AttributeInfo::readInfo(ClassReader *classReader) {


}


AttributeInfo* AttributeInfo::readAttributes(ClassReader *classReader, ConstantPool *constantPool) {
    u2 count = classReader->readU2();
    AttributeInfo* attributeInfos = new AttributeInfo[count];
    for (int i = 0; i < count; ++i) {
        attributeInfos[i].readInfo(classReader);
    }
    return attributeInfos;
}