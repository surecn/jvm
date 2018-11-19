//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_ATTRIBUTEINFO_H
#define JVM_ATTRIBUTEINFO_H

#include "../common.h"
#include "../classfile/ClassReader.h"
#include "../classfile/ConstantPool.h"

using namespace cls;

class AttributeInfo {
private:
    u2 nameIndex;
    u4 length;
    u1 *info;

public:
    void readInfo(ClassReader* classReader);

//    static AttributeInfo** readAttributes(ClassReader* classReader, ConstantPool* constantPool);
//
//    static AttributeInfo* readAttribute(ClassReader* classReader, ConstantPool* constantPool);
//
//    static AttributeInfo* newAttributeInfo(string attrName, u2 attrLen, ConstantPool* constantPool);

};

class DeprecatedAttribute : public AttributeInfo {
};

class SyntheticAttribute : public AttributeInfo {
};


class SourceFileAttribute : public AttributeInfo {
private:
    u2 sourceFileIndex;
};


class ConstantValueAttribute : public AttributeInfo {
private:
    u2 constantValueIndex;
};

class CodeAttribute : public AttributeInfo {
private:
    u2 maxStack;
    u2 maxLocals;
    u4 codeLength;
    u1* code;
//    u2 exceptionTableLength;
//    {
//        u2 startPc;
//        u2 endPc;
//        u2 handlerPc;
//        u2 catchType;
//    } exceptionTable[];

};


class ExceptionAttribute : public AttributeInfo {
private:
    u2 numberOfException;
    u2 exceptionIndexTable[];
};


class LineNumberTable : public AttributeInfo {

};






#endif //JVM_ATTRIBUTEINFO_H
