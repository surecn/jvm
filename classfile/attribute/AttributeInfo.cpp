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
#include "UnparsedAttribute.h"
#include "BootstrapMethodsAttribute.h"
#include "EnclosingMethodAttribute.h"
#include "InnerClassesAttribute.h"
#include "SignatureAttribute.h"

namespace cf {

    DeprecatedAttribute *AttributeInfo::s_attrDeprecated = new DeprecatedAttribute();
    SyntheticAttribute *AttributeInfo::s_attrSynthetic = new SyntheticAttribute();

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
//        cout << "attribute:" + *attrName << "=" << attrLen << endl;
        AttributeInfo * attributeInfo = NULL;
        if ("BootstrapMethods" == *attrName) {
            attributeInfo = new BootstrapMethodsAttribute();
        } else if ("Code" == *attrName) {
            attributeInfo = new CodeAttribute(constantPool);
        } else if ("ConstantValue" == *attrName) {
            attributeInfo = new ConstantValueAttribute();
        } else if ("Deprecated" == *attrName) {
            attributeInfo = s_attrDeprecated;
        } else if ("EnclosingMethod" == *attrName) {
            attributeInfo = new EnclosingMethodAttribute();
        } else if ("Exceptions" == *attrName) {
            attributeInfo = new ExceptionAttribute();
        } else if ("InnerClasses" == *attrName) {
            attributeInfo = new InnerClassesAttribute();
        } else if ("LineNumberTable" == *attrName) {
            attributeInfo = new LineNumberTableAttribute();
        } else if ("LocalVariableTable" == *attrName) {
            attributeInfo = new LocalVariableTableAttribute();
        } else if ("LocalVariableTypeTable" == *attrName) {
        //} else if ("MethodParameters" == *attrName) {
        //} else if ("RuntimeInvisibleAnnotations" == *attrName) {
        //} else if ("RuntimeInvisibleParameterAnnotations" == *attrName) {
        //} else if ("RuntimeInvisibleTypeAnnotations" == *attrName) {
        //} else if ("RuntimeVisibleAnnotations" == *attrName) {
        //} else if ("RuntimeVisibleParameterAnnotations" == *attrName) {
        //} else if ("RuntimeVisibleTypeAnnotations" == *attrName) {
        } else if ("Signature" == *attrName) {
            attributeInfo = new SignatureAttribute();
        } else if ("SourceFile" == *attrName) {
            attributeInfo = new SourceFileAttribute(constantPool);
        } else if ("Synthetic" == *attrName) {
            attributeInfo = new SyntheticAttribute();
        } else {
            attributeInfo = new UnparsedAttribute(attrName, attrLen);
        }
        if (attributeInfo != NULL) {
            attributeInfo->m_type = *attrName;
        }
        return attributeInfo;
    }
}