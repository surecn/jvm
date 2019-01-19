//
// Created by 郑邦国 on 2018/11/4.
//

#ifndef JVM_CLASSFILE_H
#define JVM_CLASSFILE_H


#include "../common.h"
#include "ClassReader.h"
#include "ConstantPool.h"
#include "ConstantInfo.h"
#include "Constants.h"

namespace cf {
    class ClassFile {
    private:
        u4 m_magic;
        u2 m_minorVersion;//小版本号
        u2 m_majorVersion;//大版本号
        ConstantPool* m_cp;//常量池
        u2  m_accessFlags;//访问标志
        u2  m_thisClass;
        u2  m_superClass;
        u2* m_interfaces;
        u2 m_interfacesCount;
        u2 m_methodCount;
        u2 m_fieldCount;
        MemberInfo** m_methods;
        MemberInfo** m_fields;
        //AttributeInfo* m_attributes;
        bool readAndCheckMagic(ClassReader *classReader);
        bool readAndCheckVersion(ClassReader *classReader);
        void readFields(ClassReader *classReader);
        void readMethods(ClassReader *classReader);
        AttributeInfo* readAttributes(ClassReader *classReader);
        ConstantPool* readConstantPool(ClassReader *classReader);
        ConstantInfo* readConstantInfo(ClassReader *classReader, ConstantPool* cp);

    public:
        ClassFile();
        ~ClassFile();
        string* getName(MemberInfo* memberInfo);
        string* getDescriptor(MemberInfo* memberInfo);
        void parse(byte *&classData);
        ClassFile* read(ClassReader* classReader);
        u2 getMinorVersion();
        u2 getMajorVersion();
        string* getClassName();
        string* getSuperClassName();
        string** getInterfacesNames();
        u2 getInterfaceCount();
        MemberInfo** getMethods();
        u2 getMethodCount();
        u2 getFieldCount();
        u2 getAccessFlags();
        ConstantPool* getConstantPool();
        MemberInfo **getFields() const;
    };

}


#endif //JVM_CLASSFILE_H
