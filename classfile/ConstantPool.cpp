//
// Created by 郑邦国 on 2018/11/4.
//

#include "ConstantPool.h"
#include "Constants.h"

using namespace cls;

ConstantInfo* ConstantPool::getConstantInfo(u2 index) {
    return constantInfos[index];
}

string *ConstantPool::getClassName(u2 index) {
    ConstantClassInfo *classConstantInfo = (ConstantClassInfo*)constantInfos[index];
    return classConstantInfo->getName();
}


string *ConstantPool::getUtf8(u2 index) {
    return ((ConstantUtf8Info*)getConstantInfo(index))->value();
}

ConstantPool::ConstantPool(ClassReader *classReader) {
    constantPoolSize = classReader->readU2();
    constantInfos = (ConstantInfo**)(malloc(sizeof(ConstantInfo*) * constantPoolSize));
    for (int i = 1; i < constantPoolSize; ++i) {
        byte tag = classReader->readU1();
        ConstantInfo* con = ConstantFactory::newConstantInfo(tag, this, classReader);
        constantInfos[i] = con;
        con->print();
        if (tag == CONSTANT_Double || tag == CONSTANT_Long) {
            i++;
        }
    }
}


