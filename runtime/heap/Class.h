//
// Created by 郑邦国 on 2018/12/17.
//

#ifndef JVM_CONSTANT_H
#define JVM_CONSTANT_H

#include "Method.h"
#include "Field.h"
#include "../../classfile/ClassFile.h"

namespace rt {
    extern class ClassLoader;
    class Class {
    private:
        u2 m_accessFlags;
        string *m_name;
        string *m_suerClassName;
        string **m_interfaceNames;
        u2 m_interfaceCount;
        cf::ConstantPool * m_constantPool;
        Field **m_fields;
        Method **m_method;
        ClassLoader *m_loader;
        Class *m_superClass;
        Class **m_interfaces;
        java_int m_staticSlotCount;
        java_int *m_staticVars;
    public:
        Class(cf::ClassFile *cf);
        bool isPublic();
        bool isFinal();
        bool isSuper();
        bool isInterface();
        bool isAbstract();
        bool isSynthetic();
        bool isAnnotation();
        bool isEnum();
        void setClassLoader(ClassLoader *loader);
        ClassLoader* getClassLoader();
        string *getName();
        string *getSuperClassName();
        void setSuperClass(Class *cls);
        string **getInterfaceNames();
        u2 getInterfaceCount();
        void setInterfaces(Class **cls);
    };


}


#endif //JVM_CONSTANT_H
