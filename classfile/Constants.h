//
// Created by 郑邦国 on 2018/11/23.
//

#ifndef JVM_CONSTANTS_H
#define JVM_CONSTANTS_H

#include "../common.h"
#include "ConstantInfo.h"
#include "ConstantPool.h"
#include "attribute/AttributeInfo.h"
#include "attribute/CodeAttribute.h"
#include "attribute/ConstantValueAttribute.h"

namespace cf {

    class ConstantClassInfo : public ConstantInfo {
    private:
        ConstantPool *m_cp;
        u2 m_nameIndex;
    public:
        ConstantClassInfo(ConstantPool* cp);
        string* getName();
        void print();
        void* getValue();
        void readInfo(ClassReader* classReader);
    };

    class ConstantMemberInfo : public ConstantInfo {
    private:
        u2 m_classIndex;
        u2 m_nameAndTypeIndex;
        ConstantPool *m_cp;
    public:
        ConstantMemberInfo(ConstantPool *cp);
        void print();
        void* getValue();
        string *getClassName();
        NameAndType getNameAndType();
        void readInfo(ClassReader* classReader);
    };

    class ConstantFieldRefInfo : public ConstantMemberInfo {
    private:
    public:
        ConstantFieldRefInfo(ConstantPool *cp);
    };

    class ConstantMethodRefInfo : public ConstantMemberInfo {
    private:
    public:
        ConstantMethodRefInfo(ConstantPool *cp);
    };

    class ConstantInterfaceMethodRefInfo : public ConstantMemberInfo {
    private:
    public:
        ConstantInterfaceMethodRefInfo(ConstantPool *cp);
    };

    class ConstantNameAndTypeInfo : public ConstantInfo{
    private:
        u2 m_name_index;
        u2 m_desciptor_index;
        ConstantPool *m_cp;
    public:
        ConstantNameAndTypeInfo(ConstantPool *cp);
        void print();
        void* getValue();
        u2 getNameIndex();
        u2 getDescriptorIndex();
        void readInfo(ClassReader* classReader);
    };

    class ConstantStringInfo : public ConstantInfo {
    private:
        u2 m_stringIndex;
        ConstantPool *m_cp;
    public:
        ConstantStringInfo(ConstantPool *cp);
        void print();
        void* getValue();
        void readInfo(ClassReader* classReader);
    };

    class ConstantUtf8Info : public ConstantInfo {
    private:
        u2 m_length;
        string *m_utf8;
        ConstantPool *m_cp;
    public:
        string *value();
        void print();
        void* getValue();
        void readInfo(ClassReader* classReader);
    };


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
        static MemberInfo** readMembers(ConstantPool *constantPool, ClassReader *reader, u2 *count);
    };


    class ConstantFactory {
    public:
        static ConstantInfo *readConstantInfo(ClassReader *classReader, ConstantPool *constantPool);
        static ConstantInfo *newConstantInfo(u1 tag, ConstantPool *constantPool);
    };
}


#endif //JVM_CONSTANTS_H
