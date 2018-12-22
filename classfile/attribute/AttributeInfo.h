//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_ATTRIBUTEINFO_H
#define JVM_ATTRIBUTEINFO_H

#include "../../common.h"
#include "../ClassReader.h"
#include "../ConstantPool.h"

namespace cf {
    class AttributeInfo {
    private:
//        u2 m_nameIndex;
//        u4 m_length;
//        u1 *m_info;
        string m_type;
        static AttributeInfo* readAttribute(ClassReader* classReader, cf::ConstantPool* constantPool);
    public:

        string getAttributeType();

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
