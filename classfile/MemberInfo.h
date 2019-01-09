//
// Created by 郑邦国 on 2018/11/4.
//

#ifndef JVM_MEMBERINFO_H
#define JVM_MEMBERINFO_H

#include "../common.h"
#include "ConstantPool.h"
#include "../attribute/AttributeInfo.h"

namespace cls {

    class MemberInfo {
    private:
        ConstantPool *constantPool;
        u2  accessFlags;
        u2  nameIndex;
        u2  descriptorIndex;
        AttributeInfo**  attributeInfos;
    public:
        MemberInfo(ConstantPool *cp, ClassReader* classReader);

        u2 getNameIndex() {
            return nameIndex;
        };

        u2 getDescriptorIndex() {
            return descriptorIndex;
        };

        static MemberInfo** readMembers(ConstantPool *constantPool, ClassReader *reader);
    };
}


#endif //JVM_MEMBERINFO_H
