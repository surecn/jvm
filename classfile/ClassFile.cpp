//
// Created by 郑邦国 on 2018/11/4.
//

#include "ClassFile.h"
#include "ClassReader.h"
#include "ConstantDoubleInfo.h"
#include "ConstantLongInfo.h"
#include "ConstantFactory.h"

<<<<<<< HEAD
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
    superClass = classReader->readU2();
    interfaces = classReader->readU2s();
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
=======
namespace cf {
    ClassFile::ClassFile() {}

    void ClassFile::parse(byte *&classData) {
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
        m_cp = readConstantPool(classReader);
        //TODO 类访问标志
        m_accessFlags = classReader->readU2();
        m_thisClass = classReader->readU2();
        cout << "classFile className:" << *m_cp->getClassName(m_thisClass) << endl;
        m_superClass = classReader->readU2();
        //cout << "super className:" << *m_cp->getClassName(m_superClass) << endl;
        m_interfaces = classReader->readU2s(&m_interfacesCount);
        readFields(classReader);
        readMethods(classReader);

    }

    static ConstantPool* readConstanPool(ClassReader *classReader) {
        return new ConstantPool(classReader);
    }

    bool ClassFile::readAndCheckMagic(ClassReader *classReader) {
        m_magic = classReader->readU4();
        if (m_magic == (u4)0XCAFEBABE) {//0xCAFEBABE
            return true;
        }
        cout << "java.lang.ClassFormatError: magic" << endl;
        return false;
    }

    bool ClassFile::readAndCheckVersion(ClassReader *classReader) {
        m_minorVersion = classReader->readU2();
        m_majorVersion = classReader->readU2();
        switch (m_majorVersion) {
            case 45:
                return true;
            case 46:
            case 47:
            case 48:
            case 49:
            case 50:
            case 51:
            case 52:
                if (m_minorVersion == 0) {
                    return true;
                }
        }
        cout << "java.lang.UnsupportedClassVersionError!" << endl;
        return false;
    }

    string* ClassFile::getName(MemberInfo *memberInfo) {
        return m_cp->getUtf8(memberInfo->getNameIndex());
    }

    string* ClassFile::getDescriptor(MemberInfo *memberInfo) {
        return m_cp->getUtf8(memberInfo->getDescriptorIndex());
    }

    ConstantPool* ClassFile::readConstantPool(ClassReader *classReader) {
        return new ConstantPool(classReader);
    }

    void ClassFile::readFields(ClassReader *classReader) {
        m_fields = MemberInfo::readMembers(m_cp, classReader, &m_fieldCount);
    }

    void ClassFile::readMethods(ClassReader *classReader) {
        m_methods = MemberInfo::readMembers(m_cp, classReader, &m_methodCount);
    }

    ConstantInfo* ClassFile::readConstantInfo(ClassReader *classReader, ConstantPool* cp) {
        return ConstantFactory::readConstantInfo(classReader, cp);
    }

    u2 ClassFile::getMinorVersion() {
        return m_minorVersion;
    }

    u2 ClassFile::getMajorVersion() {
        return m_majorVersion;
    }

    string* ClassFile::getClassName() {
        return m_cp->getClassName(this->m_thisClass);
    }

    string* ClassFile::getSuperClassName() {
        if (m_superClass > 0) {
            return m_cp->getClassName(this->m_superClass);
        }
        return 0;
    }

    string** ClassFile::getInterfacesNames() {
        if (m_interfaces) {
            string **names = new string*[m_interfacesCount];
            for (int i = 0; i < m_interfacesCount; ++i) {
                names[i] = m_cp->getClassName(this->m_interfaces[i]);
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
            }
            return names;
        }
        return NULL;
    }

    u2 ClassFile::getInterfaceCount() {
        return m_interfacesCount;
    }

    MemberInfo** ClassFile::getMethods() {
        return m_methods;
    }

    u2 ClassFile::getMethodCount() {
        return m_methodCount;
    }

    MemberInfo **ClassFile::getFields() const {
        return m_fields;
    }

    u2 ClassFile::getFieldCount() {
        return m_fieldCount;
    }

    u2 ClassFile::getAccessFlags() {
        return m_accessFlags;
    }

    ConstantPool* ClassFile::getConstantPool() {
        return m_cp;
    }
<<<<<<< HEAD
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
=======
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e

void ClassFile::readMethods(ClassReader *classReader) {
    methods = MemberInfo::readMembers(constantPool, classReader);
}

ConstantInfo* ClassFile::readConstantInfo(ClassReader *classReader, ConstantPool* cp) {
    return ConstantFactory::readConstantInfo(classReader, cp);
}