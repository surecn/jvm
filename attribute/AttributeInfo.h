//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_ATTRIBUTEINFO_H
#define JVM_ATTRIBUTEINFO_H

#include "../common.h"
#include "../ClassReader.h"
#include "../ConstantPool.h"

class AttributeInfo {
private:
    u2 nameIndex;
    u4 length;
    u1 *info;

public:
    void readInfo(ClassReader* classReader);

    static AttributeInfo* readAttributes(ClassReader* classReader, ConstantPool* constantPool);

};


#endif //JVM_ATTRIBUTEINFO_H
