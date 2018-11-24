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
        string* getName(MemberInfo* memberInfo);
        string* getDescriptor(MemberInfo* memberInfo);
    public:
        ClassFile();
        ~ClassFile();
        void load(byte* &classData);
        ClassFile* read(ClassReader* classReader);
        u2 getMinorVersion();
        u2 getMajorVersion();
        string* getClassName();
        string* getSuperClassName();
        string* getInterfacesNames();
    };

}


#endif //JVM_CLASSFILE_H
