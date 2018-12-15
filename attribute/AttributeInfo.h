//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_ATTRIBUTEINFO_H
#define JVM_ATTRIBUTEINFO_H

#include "../common.h"
#include "../classfile/ClassReader.h"
#include "../classfile/ConstantPool.h"

namespace cls {
    class AttributeInfo {
    private:
        u2 nameIndex;
        u4 length;
        u1 *info;
        static AttributeInfo* readAttribute(ClassReader* classReader, ConstantPool* constantPool);
    public:

        virtual void readInfo(ClassReader* classReader) = 0;

        static AttributeInfo** readAttributes(ClassReader* classReader, ConstantPool* constantPool, u2 count);

        static AttributeInfo* newAttributeInfo(string *attrName, u2 attrLen, ConstantPool* constantPool);

    };

    class DeprecatedAttribute : public AttributeInfo {

    public:
        void readInfo(ClassReader* classReader) {
        }
    };

    class SyntheticAttribute : public AttributeInfo {
    public:
        void readInfo(ClassReader* classReader) {
        }
    };



}



#endif //JVM_ATTRIBUTEINFO_H
