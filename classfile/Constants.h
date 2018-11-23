//
// Created by 郑邦国 on 2018/11/23.
//

#ifndef JVM_CONSTANTS_H
#define JVM_CONSTANTS_H

#include "../common.h"
#include "ConstantInfo.h"
#include "ConstantPool.h"
#include "../attribute/AttributeInfo.h"

namespace cls {
    class ConstantFloatInfo : public ConstantInfo {
    private:
        float value;
    public:
        ConstantFloatInfo(ClassReader *classReader);
        void print();
    };

    class ConstantFieldRefInfo : public ConstantInfo{
    private:
        u2 classIndex;
        u2 nameAndTypeIndex;
    public:
        ConstantInfo* readInfo(ClassReader* classReader, ConstantPool cp);
    };

    class ConstantDoubleInfo : public ConstantInfo {
    private:
        double value;
    public:
        ConstantDoubleInfo(ClassReader* classReader);
        void print();
    };

    class ConstantClassInfo : public ConstantInfo {
    private:
        ConstantPool *constantPool;
        u2 nameIndex;
    public:
        ConstantClassInfo(ClassReader* classReader, ConstantPool* cp);
        string* getName();
        void print();
    };

    class ConstantIntegerInfo : public ConstantInfo {
    private:
        int value;
    public:
        ConstantIntegerInfo(ClassReader *classReader);
        void print();
    };

    class ConstantLongInfo : public ConstantInfo {
    private:
        long value;
    public:
        ConstantLongInfo(ClassReader * classReader);
        void print();
    };

    class ConstantMemberInfo : public ConstantInfo {
    private:
        u2 classIndex;
        u2 nameAndTypeIndex;
        ConstantPool *constantPool;
    public:
        ConstantMemberInfo(ClassReader* classReader, ConstantPool *cp);
        void print();
    };

    class ConstantNameAndTypeInfo : public ConstantInfo{
    private:
        u2 nameIndex;
        u2 desciptorIndex;
        ConstantPool *constantPool;
    public:
        ConstantNameAndTypeInfo(ClassReader* classReader, ConstantPool *cp);
        void print();
    };

    class ConstantStringInfo : public ConstantInfo {
    private:
        u2 stringIndex;
        ConstantPool *constantPool;
    public:
        ConstantStringInfo(ClassReader* classReader, ConstantPool *cp);
        void print();
    };

    class ConstantUtf8Info : public ConstantInfo {
    private:
        u2 length;
        string bytes;
    public:
        ConstantUtf8Info(ClassReader* classReader);
        string *value();
        void print();
    };


    class MemberInfo {
    private:
        ConstantPool *constantPool;
        u2  accessFlags;
        u2  nameIndex;
        u2  descriptorIndex;
        AttributeInfo**  attributeInfos;
    public:
        MemberInfo(ConstantPool *cp, ClassReader* classReader);
        u2 getNameIndex();
        u2 getDescriptorIndex();
        static MemberInfo** readMembers(ConstantPool *constantPool, ClassReader *reader);
    };


    class ConstantFactory {
    public:
        static ConstantInfo *readConstantInfo(ClassReader *classReader, ConstantPool *constantPool);
        static ConstantInfo *newConstantInfo(u1 tag, ConstantPool *constantPool, ClassReader *classReader);
    };
}


#endif //JVM_CONSTANTS_H
