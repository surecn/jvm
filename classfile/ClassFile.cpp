//
// Created by 郑邦国 on 2018/11/4.
//

#include "ClassFile.h"
#include "ClassReader.h"

namespace cls {
    ClassFile::ClassFile() {}

    ClassFile::~ClassFile() {
        delete interfaces;
        delete [] methods;
        delete [] fields;
        delete attributes;
    }

    void ClassFile::load(byte *&classData) {
        ClassReader classReader(classData);
        read(&classReader);
    }

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
        fields = MemberInfo::readMembers(constantPool, classReader, &_fieldCount);
    }

    void ClassFile::readMethods(ClassReader *classReader) {
        methods = MemberInfo::readMembers(constantPool, classReader, &_methodCount);
    }

    ConstantInfo* ClassFile::readConstantInfo(ClassReader *classReader, ConstantPool* cp) {
        return ConstantFactory::readConstantInfo(classReader, cp);
    }

    u2 ClassFile::getMinorVersion() {
        return minorVersion;
    }

    u2 ClassFile::getMajorVersion() {
        return majorVersion;
    }

    string* ClassFile::getClassName() {
        constantPool->getClassName(this->thisClass);
    }

    string* ClassFile::getSuperClassName() {
        if (superClass > 0) {
            return constantPool->getClassName(this->superClass);
        }
        return 0;
    }

    string* ClassFile::getInterfacesNames() {
        if (interfaces) {
            return constantPool->getClassName(*this->interfaces);
        }
        return 0;
    }

    MemberInfo** ClassFile::getMethods() {
        return methods;
    }

    u2 ClassFile::getMethodCount() {
        return _methodCount;
    }

    u2 ClassFile::getFieldCount() {
        return _fieldCount;
    }

}