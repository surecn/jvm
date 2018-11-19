//
// Created by 郑邦国 on 2018/11/4.
//

#include "ConstantPool.h"

using namespace cls;

ConstantInfo* ConstantPool::getConstantInfo(u2 index) {
    return constantInfos[index];
}

string* ConstantPool::getClassName(u2 index) {
//    ClassConstantInfo *classConstantInfo = constantInfos[index];
//    return this->getUtf8(classConstantInfo->index);
    return NULL;
}


string* ConstantPool::getUtf8(u2 index) {
    return &getConstantInfo(index)->str;
}

void ConstantPool::readConstantPool(ClassReader *classReader) {

}


