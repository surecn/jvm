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

namespace cls {
    class ClassFile {
    private:
        u4 magic;
        u2  minorVersion;//小版本号
        u2  majorVersion;//大版本号
        ConstantPool* constantPool;//常量池
        u2  accessFlags;//访问标志
        u2  thisClass;
        u2  superClass;
        u2*  interfaces;
        u2 interfacesLength;
        u2 _methodCount;
        u2 _fieldCount;
        cls::MemberInfo** methods;
        cls::MemberInfo** fields;
        AttributeInfo* attributes;
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
        void load(byte* &classData);
        ClassFile* read(ClassReader* classReader);
        u2 getMinorVersion();
        u2 getMajorVersion();
        string* getClassName();
        string* getSuperClassName();
        string* getInterfacesNames();
        MemberInfo** getMethods();
        u2 getMethodCount();
        u2 getFieldCount();
    };

}


#endif //JVM_CLASSFILE_H
