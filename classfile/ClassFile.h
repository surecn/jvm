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

    };

}


#endif //JVM_CLASSFILE_H
