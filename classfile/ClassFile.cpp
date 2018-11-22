//
// Created by 郑邦国 on 2018/11/4.
//

#include "ClassFile.h"
#include "ClassReader.h"
#include "ConstantDoubleInfo.h"
#include "ConstantLongInfo.h"
#include "ConstantFactory.h"

using namespace cls;

ClassFile* ClassFile::read(ClassReader *classReader) {
    if (!readAndCheckMagic(classReader)) {
        return NULL;
    }
    if (!readAndCheckVersion(classReader)) {
        return NULL;
    }
    constantPool = readConstantPool(classReader);
    //TODO 类访问标志
    accessFlags = classReader->readU2();
    thisClass = classReader->readU2();
    cout << "classFile className:" << *constantPool->getClassName(thisClass) << endl;
    superClass = classReader->readU2();
    cout << "super className:" << *constantPool->getClassName(superClass) << endl;
    interfaces = classReader->readU2s(&interfacesLength);
    readFields(classReader);
    readMethods(classReader);
}

static ConstantPool* readConstanPool(ClassReader *classReader) {
    return new ConstantPool(classReader);
}

bool ClassFile::readAndCheckMagic(ClassReader *classReader) {
    magic = classReader->readU4();
    if (magic == (u4)0XCAFEBABE) {//0xCAFEBABE
        return true;
    }
    cout << "java.lang.ClassFormatError: magic" << endl;
    return false;
}

bool ClassFile::readAndCheckVersion(ClassReader *classReader) {
    minorVersion = classReader->readU2();
    majorVersion = classReader->readU2();
    switch (majorVersion) {
        case 45:
            return true;
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
            if (minorVersion == 0) {
                return true;
            }
    }
    cout << "java.lang.UnsupportedClassVersionError!" << endl;
    return false;
}

string* ClassFile::getName(MemberInfo *memberInfo) {
    return constantPool->getUtf8(memberInfo->getNameIndex());
}

string* ClassFile::getDescriptor(MemberInfo *memberInfo) {
    return constantPool->getUtf8(memberInfo->getDescriptorIndex());
}


ConstantPool* ClassFile::readConstantPool(ClassReader *classReader) {
    return new ConstantPool(classReader);
}

void ClassFile::readFields(ClassReader *classReader) {
    fields = MemberInfo::readMembers(constantPool, classReader);
}

void ClassFile::readMethods(ClassReader *classReader) {
    methods = MemberInfo::readMembers(constantPool, classReader);
}

ConstantInfo* ClassFile::readConstantInfo(ClassReader *classReader, ConstantPool* cp) {
    return ConstantFactory::readConstantInfo(classReader, cp);
}