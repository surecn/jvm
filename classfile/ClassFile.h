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
<<<<<<< HEAD

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
        cls::MemberInfo** methods;
        cls::MemberInfo** fields;
        AttributeInfo* attributes;

        bool readAndCheckMagic(ClassReader *classReader);

        bool readAndCheckVersion(ClassReader *classReader);

        void readFields(ClassReader *classReader);

        void readMethods(ClassReader *classReader);

=======
        u4 m_magic;
        u2 m_minorVersion;//小版本号
        u2 m_majorVersion;//大版本号
        ConstantPool* m_cp;//常量池
        u2  m_accessFlags;//访问标志
        u2  m_thisClass;
        u2  m_superClass;
        u2*  m_interfaces;
        u2 m_interfacesCount;
        u2 m_methodCount;
        u2 m_fieldCount;
        MemberInfo** m_methods;
        MemberInfo** m_fields;
        AttributeInfo* m_attributes;
        bool readAndCheckMagic(ClassReader *classReader);
        bool readAndCheckVersion(ClassReader *classReader);
        void readFields(ClassReader *classReader);
        void readMethods(ClassReader *classReader);
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
        AttributeInfo* readAttributes(ClassReader *classReader);
        ConstantPool* readConstantPool(ClassReader *classReader);
        ConstantInfo* readConstantInfo(ClassReader *classReader, ConstantPool* cp);

    public:
        ClassFile();
        string* getName(MemberInfo* memberInfo);
        string* getDescriptor(MemberInfo* memberInfo);
<<<<<<< HEAD
    public:

        ClassFile(byte* &classData){
            ClassReader classReader(classData);
            read(&classReader);
        }

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

=======
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
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
    };

}


#endif //JVM_CLASSFILE_H
