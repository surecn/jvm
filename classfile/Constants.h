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
    class ConstantFloatInfo : public ConstantInfo {
    private:
        float m_value;
    public:
        ConstantFloatInfo(ClassReader *classReader);
        void print();
        void* getValue();
    };

    class ConstantDoubleInfo : public ConstantInfo {
    private:
        double m_value;
    public:
        ConstantDoubleInfo(ClassReader* classReader);
        void print();
        void* getValue();
    };

    class ConstantClassInfo : public ConstantInfo {
    private:
        ConstantPool *m_constantPool;
        u2 m_nameIndex;
    public:
        ConstantClassInfo(ClassReader* classReader, ConstantPool* cp);
        string* getName();
        void print();
        void* getValue();
    };

    class ConstantIntegerInfo : public ConstantInfo {
    private:
        int m_value;
    public:
        ConstantIntegerInfo(ClassReader *classReader);
        void print();
        void* getValue();
    };

    class ConstantLongInfo : public ConstantInfo {
    private:
        long m_value;
    public:
        ConstantLongInfo(ClassReader * classReader);
        void print();
        void* getValue();
    };

    class ConstantMemberInfo : public ConstantInfo {
    private:
        u2 m_classIndex;
        u2 m_nameAndTypeIndex;
        ConstantPool *m_constantPool;
    public:
        ConstantMemberInfo(ClassReader* classReader, ConstantPool *cp);
        void print();
        void* getValue();
        string *getClassName();
        NameAndType getNameAndType();
    };

    class ConstantFieldRefInfo : public ConstantMemberInfo {
    private:
    public:
        ConstantInfo* readInfo(ClassReader* classReader, ConstantPool cp);
        void* getValue();
    };

    class ConstantMethodRefInfo : public ConstantMemberInfo {
    private:
    public:
        ConstantInfo* readInfo(ClassReader* classReader, ConstantPool cp);
        void* getValue();
    };

    class ConstantInterfaceMethodRefInfo : public ConstantMemberInfo {
    private:
    public:
        ConstantInfo* readInfo(ClassReader* classReader, ConstantPool cp);
        void* getValue();
    };

    class ConstantNameAndTypeInfo : public ConstantInfo{
    private:
        u2 m_name_index;
        u2 m_desciptor_index;
        ConstantPool *constantPool;
    public:
        ConstantNameAndTypeInfo(ClassReader* classReader, ConstantPool *cp);
        void print();
        void* getValue();
        u2 getNameIndex();
        u2 getDescriptorIndex();
    };

    class ConstantStringInfo : public ConstantInfo {
    private:
        u2 m_stringIndex;
        ConstantPool *m_constantPool;
    public:
        ConstantStringInfo(ClassReader* classReader, ConstantPool *cp);
        void print();
        void* getValue();
    };

    class ConstantUtf8Info : public ConstantInfo {
    private:
        u2 m_length;
        string m_bytes;
    public:
        ConstantUtf8Info(ClassReader* classReader);
        string *value();
        void print();
        void* getValue();
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
        static ConstantInfo *newConstantInfo(u1 tag, ConstantPool *constantPool, ClassReader *classReader);
    };
}


#endif //JVM_CONSTANTS_H
