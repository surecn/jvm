//
// Created by 郑邦国 on 2018/11/4.
//

#include "ClassFile.h"
#include "ClassReader.h"

ClassFile* ClassFile::read(ClassReader *classReader) {
    readAndCheckMagic(classReader);
    readAndCheckVersion(classReader);
    //TODO 类访问标志
    accessFlags = classReader->readU2();
    thisClass = classReader->readU2();
    superClass = classReader->readU2();
    interfaces = classReader->readU2s();

}

void ClassFile::readAndCheckMagic(ClassReader *classReader) {
    magic = classReader->readU4();
    if (magic != 0xCAFEBABE) {
        cout << "java.lang.ClassFormatError: magic" << endl;
    }
}

void ClassFile::readAndCheckVersion(ClassReader *classReader) {
    minorVersion = classReader->readU2();
    majorVersion = classReader->readU2();
    switch (majorVersion) {
        case 45:
            return;
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
            if (minorVersion == 0) {
                return;
            }
    }
    cout << "java.lang.UnsupportedClassVersionError!" << endl;
}

MemberInfo* ClassFile::readMemebers(ClassReader *classReader) {
    u2 accessFlags = classReader->readU2();
    u2 nameIndex = classReader->readU2();
    u2 descriptorIndex =classReader->readU2();
    AttributeInfo* attributeInfo = this->readAttributes(classReader);
    return new MemberInfo(constantPool, accessFlags, nameIndex, descriptorIndex, attributeInfo);
}

AttributeInfo* ClassFile::readAttributes(ClassReader *classReader) {
    AttributeInfo* attributeInfo = new AttributeInfo();
    return attributeInfo;
}

string* ClassFile::getName(MemberInfo *memberInfo) {
    return constantPool->getUtf8(memberInfo->getNameIndex());
}

string* ClassFile::getDescriptor(MemberInfo *memberInfo) {
    return constantPool->getUtf8(memberInfo->getDescriptorIndex());
}


ConstantPool* ClassFile::readConstantPool(ClassReader *classReader) {
    u2 cpCount = classReader->readU2();
    ConstantPool* constantPool1;
    ConstantInfo **constantInfo = new ConstantInfo*[cpCount];
    for (int i = 1; i < cpCount; ++i) {
        constantInfo[i] = readConstantInfo(classReader, constantPool1);
        if (typeid(constantInfo[i]) == typeid(ConstantDoubleInfo) || typeid(constantInfo[i]) == typeid(ConstantLongInfo)) {
            i++;
        }
    }
    return constantPool1;
}

ConstantInfo* ClassFile::readConstantInfo(ClassReader *classReader, ConstantPool* cp) {

}