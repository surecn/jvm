//
// Created by 郑邦国 on 2018/11/4.
//

#ifndef JVM_CLASSFILE_H
#define JVM_CLASSFILE_H


#include "../common.h"
#include "MemberInfo.h"
#include "ClassReader.h"
#include "ConstantPool.h"
#include "ConstantInfo.h"

namespace cls {

    class ClassFile {
    private:

//    u4                  magic;
//    u2                  minor_version;
//    u2                  major_version;
//    u2                  constant_pool_count;
//    cp_info             constant_pool[constan_pool_count - 1];
//    u2                  access_flags;
//    u2                  this_class;
//    u2                  super_class;
//    u2                  interfaces_count;
//    u2                  interfaces[interfaces_count];
//    u2                  fields_count;
//    field_info          fields[fields_count];
//    u2                  methods_count;
//    method_info         methods[methods_count];
//    u2                  attributes_count;
//    attribute_info      attributes[attributes_count];

        u4 magic;
        u2  minorVersion;
        u2  majorVersion;
        ConstantPool* constantPool;
        u2  accessFlags;
        u2  thisClass;
        u2  superClass;
        u2*  interfaces;
        cls::MemberInfo* methods;
        cls::MemberInfo* fields;
        AttributeInfo* attributes;

        void readAndCheckMagic(ClassReader *classReader);

        void readAndCheckVersion(ClassReader *classReader);

        cls::MemberInfo* readMemebers(ClassReader *classReader);

        AttributeInfo* readAttributes(ClassReader *classReader);

        ConstantPool* readConstantPool(ClassReader *classReader);

        ConstantInfo* readConstantInfo(ClassReader *classReader, ConstantPool* cp);

        string* getName(MemberInfo* memberInfo);

        string* getDescriptor(MemberInfo* memberInfo);
    public:

        ClassFile* read(ClassReader* classReader);

        inline u2 getMinorVersion() {
            return minorVersion;
        }

        inline u2 getMajorVersion() {
            return majorVersion;
        }

        inline string* getClassName() {
            constantPool->getClassName(this->thisClass);
        }

        inline string* getSuperClassName() {
            if (superClass > 0) {
                return constantPool->getClassName(this->superClass);
            }
            return 0;
        }

        inline string* getInterfacesNames() {
            if (interfaces) {
                return constantPool->getClassName(*this->interfaces);
            }
            return 0;
        }

        static void ParseClassFile(byte* &classData, ClassFile* classFile) {
            ClassReader classReader(classData);
            classFile->read(&classReader);
        }

    };

}


#endif //JVM_CLASSFILE_H
