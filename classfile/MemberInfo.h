//
// Created by 郑邦国 on 2018/11/4.
//

#ifndef JVM_MEMBERINFO_H
#define JVM_MEMBERINFO_H

#include "../common.h"
#include "ConstantPool.h"
#include "attribute/AttributeInfo.h"
#include "attribute/CodeAttribute.h"
#include "attribute/ConstantValueAttribute.h"

namespace cf {

    class MemberInfo {
    private:
        ConstantPool *m_constantPool;
        u2  m_accessFlags;
        u2  m_nameIndex;
        u2  m_descriptorIndex;
        u2  m_attributeCount;
        AttributeInfo**  m_attributeInfos;
    public:
        MemberInfo(ConstantPool *cp, ClassReader* classReader);
        ~MemberInfo();
        u2 getNameIndex();
        u2 getDescriptorIndex();
        CodeAttribute* getCodeAttribute();
        u2 getAccessFlags();
        string *getName();
        string *getDescriptor();
        ConstantValueAttribute* getConstantValueAttribute();
        static MemberInfo** readMembers(ClassReader *reader, ConstantPool *constantPool, u2 *count);
    };
}


#endif //JVM_MEMBERINFO_H
