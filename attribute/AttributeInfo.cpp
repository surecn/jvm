//
// Created by 郑邦国 on 2018/11/10.
//

#include "AttributeInfo.h"


void AttributeInfo::readInfo(ClassReader *classReader) {

}
//
//
//AttributeInfo** AttributeInfo::readAttributes(ClassReader *classReader, ConstantPool *constantPool) {
//    u2 count = classReader->readU2();
//    AttributeInfo** attributeInfos = new AttributeInfo*[count];
//    for (int i = 0; i < count; ++i) {
//        attributeInfos[i]->readInfo(classReader);
//        readAttribute(classReader, constantPool);
//    }
//    return attributeInfos;
//}
//
//AttributeInfo* AttributeInfo::readAttribute(ClassReader *classReader, ConstantPool *constantPool) {
//    u2 attrNameIndex = classReader->readU2();
//    string* attrName = constantPool->getUtf8(attrNameIndex);
//    int attLen = classReader->readU4();
//    return NULL;
//}
//
//AttributeInfo* AttributeInfo::newAttributeInfo(string attrName, u2 attrLen, ConstantPool *constantPool) {
//    if ("Code" == attrName) {
//
//    } else if ("ConstantValue" == attrName) {
//
//    } else if ("Deprecated" == attrName) {
//
//    } else if ("Exceptions" == attrName) {
//
//    } else if ("LineNumberTable" == attrName) {
//
//    } else if ("LocalVariableTable" == attrName) {
//
//    } else if ("SourceFile" == attrName) {
//
//    } else if ("Synthetic" == attrName) {
//
//    } else {
//
//    }
//    return NULL;
//}