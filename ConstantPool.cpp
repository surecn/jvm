//
// Created by 郑邦国 on 2018/11/4.
//

#include "ConstantPool.h"


ConstantInfo* ConstantPool::getConstantInfo(u2 index) {
    return constantInfos[index];
}

string* ConstantPool::getClassName(uint16 index) {
    ClassConstantInfo *classConstantInfo = constantInfos[index];
    return this->getUtf8(classConstantInfo->index);
}


string* ConstantPool::getUtf8(u2 index) {
    return &getConstantInfo(index)->str;
}


