//
// Created by 郑邦国 on 2018/12/17.
//

#ifndef JVM_CONSTANT_H
#define JVM_CONSTANT_H

#include "Method.h"
#include "Field.h"
#include "../../classfile/ClassFile.h"
#include "../../common/SlotArray.h"
#include "Object.h"

namespace rt {
    extern class ClassLoader;
    extern class ConstantPool;
    class Class {
    private:
        u2 m_accessFlags;
        string *m_name;
        string *m_suerClassName;
        string **m_interfaceNames;
        u2 m_interfaceCount;
        ConstantPool * m_cp;
        Field **m_fields;
        u4 m_fieldCount;
        Method **m_method;
        u4 m_methodCount;
        ClassLoader *m_loader;
        Class *m_superClass;
        Class **m_interfaces;
        java_int m_instanceSlotCount;
        java_int m_staticSlotCount;
        SlotArray *m_staticVars;
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
        ConstantPool* getConstantPool() const;
        Field **getFields() const;
        Method **getMethod() const;
        u4 getFieldCount() const;
        u4 getMethodCount() const;
        void setClassLoader(ClassLoader *loader);
        ClassLoader* getClassLoader();
        string *getName();
        string *getSuperClassName();
        void setSuperClass(Class *cls);
        Class* getSuperClass();
        string **getInterfaceNames();
        u2 getInterfaceCount();
        void setInterfaces(Class **cls);
        Class **getInterfaces();
        java_int getInstanceSlotCount() const;
        void setInstanceSlotCount(java_int m_instanceSlotCount);
        java_int getStaticSlotCount() const;
        void setStaticSlotCount(java_int m_staticSlotCount);
        SlotArray *getStaticVars() const;
        void setStaticVars(SlotArray *m_staticVars);
        string getPackageName();
        bool isAccessibleTo(Class *other);
        bool isSubClassOf(Class *cls);
        Object* newObject();
        bool isAssignableFrom(Class *other);
        bool isImplements(Class *other);
        bool isSubInterfaceOf(rt::Class *other);
        Method* getMainMethod();
        Method* getStaticMethod(string *name, string *descriptor);
    };


}


#endif //JVM_CONSTANT_H
