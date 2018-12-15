//
// Created by 郑邦国 on 2018/11/10.
//

#include "AttributeInfo.h"
#include "CodeAttribute.h"
#include "ConstantValueAttribute.h"
#include "LineNumberAttribute.h"
#include "ExceptionAttribute.h"
#include "LocalVariableTableAttribute.h"
#include "SourceFileAttribute.h"

namespace cls {

    AttributeInfo** AttributeInfo::readAttributes(ClassReader *classReader, ConstantPool *constantPool, u2 count) {
        AttributeInfo** attributeInfos = new AttributeInfo*[count];
        for (int i = 0; i < count; ++i) {
            attributeInfos[i] = readAttribute(classReader, constantPool);
        }
        return attributeInfos;
    }

    AttributeInfo* AttributeInfo::readAttribute(ClassReader *classReader, ConstantPool *constantPool) {
        u2 attrNameIndex = classReader->readU2();
        string* attrName = constantPool->getUtf8(attrNameIndex);
        int attLen = classReader->readU4();
        AttributeInfo* attributeInfo = newAttributeInfo(attrName, attLen, constantPool);
        attributeInfo->readInfo(classReader);
        return attributeInfo;
    }

    AttributeInfo* AttributeInfo::newAttributeInfo(string *attrName, u2 attrLen, ConstantPool *constantPool) {
        cout << "attribute:" + *attrName << endl;
        if ("Code" == *attrName) {
            return new CodeAttribute(constantPool);
        } else if ("ConstantValue" == *attrName) {
            return new ConstantValueAttribute();
        } else if ("Deprecated" == *attrName) {
            return new DeprecatedAttribute();
        } else if ("Exceptions" == *attrName) {
            return new ExceptionAttribute();
        } else if ("LineNumberTable" == *attrName) {
            return new LineNumberTableAttribute();
        } else if ("LocalVariableTable" == *attrName) {
            return new LocalVariableTableAttribute();
        } else if ("SourceFile" == *attrName) {
            return new SourceFileAttribute(constantPool);
        } else if ("Synthetic" == *attrName) {
            return new SyntheticAttribute();
        } else {
            cout << "UnparsedAttribute:" + *attrName;
        }
        return NULL;
    }
}