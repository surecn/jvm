//
// Created by 郑邦国 on 2018/11/4.
//

#ifndef JVM_MEMBERINFO_H
#define JVM_MEMBERINFO_H

#include "common.h"
#include "ConstantPool.h"
#include "AttributeInfo.h"

class MemberInfo {
private:
    ConstantPool *constantPool;
    u2  accessFlags;
    u2  nameIndex;
    u2  descriptorIndex;
    AttributeInfo*  attributeInfos;
public:
    MemberInfo(ConstantPool *cp, u2 af, u2 ni, u2 di, AttributeInfo* ai)
        :constantPool(cp),accessFlags(af),nameIndex(ni),descriptorIndex(di),attributeInfos(ai) {}

    u2 getNameIndex() {
        return nameIndex;
    }

    u2 getDescriptorIndex() {
        return descriptorIndex;
    }
};


#endif //JVM_MEMBERINFO_H
