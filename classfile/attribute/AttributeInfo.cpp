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

namespace cf {

    string AttributeInfo::getAttributeType() {
        return m_type;
    }

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
        if (attributeInfo != NULL) {
            attributeInfo->readInfo(classReader);
        }
        return attributeInfo;
    }

    AttributeInfo* AttributeInfo::newAttributeInfo(string *attrName, u2 attrLen, ConstantPool *constantPool) {
        cout << "attribute:" + *attrName << endl;
        AttributeInfo * attributeInfo = NULL;
        if ("Code" == *attrName) {
            attributeInfo = new CodeAttribute(constantPool);
        } else if ("ConstantValue" == *attrName) {
            attributeInfo = new ConstantValueAttribute();
        } else if ("Deprecated" == *attrName) {
            attributeInfo = new DeprecatedAttribute();
        } else if ("Exceptions" == *attrName) {
            attributeInfo = new ExceptionAttribute();
        } else if ("LineNumberTable" == *attrName) {
            attributeInfo = new LineNumberTableAttribute();
        } else if ("LocalVariableTable" == *attrName) {
            attributeInfo = new LocalVariableTableAttribute();
        } else if ("SourceFile" == *attrName) {
            attributeInfo = new SourceFileAttribute(constantPool);
        } else if ("Synthetic" == *attrName) {
            attributeInfo = new SyntheticAttribute();
        } else {
            cout << "UnparsedAttribute:" + *attrName;
        }
        if (attributeInfo != NULL) {
            attributeInfo->m_type = *attrName;
        }
        return attributeInfo;
    }
}