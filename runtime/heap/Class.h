//
// Created by 郑邦国 on 2018/12/17.
//

#ifndef JVM_CLASS_H
#define JVM_CLASS_H

#include "Method.h"
#include "Field.h"
#include "../../classfile/ClassFile.h"
#include "Object.h"
#include "../Thread.h"
#include <map>

namespace rt {
    extern class ClassLoader;
    extern class ConstantPool;
    extern class ArrayClass;
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
        Method **m_methods;
        u4 m_methodCount;
        ClassLoader *m_loader;
        Class *m_superClass;
        Class **m_interfaces;
        java_int m_instanceSlotCount;
        java_int m_staticSlotCount;
        SlotArray *m_staticVars;
        bool m_initStarted;
        Object *m_jClass;
        string getArrayClassName(string className);
        string toDescriptor(string string);
        static map<string, string> *s_primitiveTypes;
        void startInit();
        void scheduleClinit(Thread *thread);
        void initSuperClass(Thread *thread);
    public:

        Class(int accessFlags, string *name, ClassLoader *classLoader,
              bool initStarted, Class *superClass, Class **interfaces, int interfaceCount);
        Class(cf::ClassFile *cf);
        ~Class();
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
        Method **getMethods() const;
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
        bool isSuperClassOf(Class *cls);
        bool isAssignableFrom(Class *other);
        bool isImplements(Class *other);
        bool isSubInterfaceOf(rt::Class *other);
        Method* getMainMethod();
        Method* getClinitMethod();
        Method* getStaticMethod(string *name, string *descriptor);
        ArrayClass* getArrayClass();
        static map<string, string>* getPrimitiveTypes();
        bool isArray();
        bool isJlObject();
        bool isJlCloneable();
        bool isJioSerializable();
        bool isSuperInterfaceOf(Class *iface);
        Object *getJClass() const;
        void setJClass(Object *jClass);

        Method *getMethod(string *name, string *descriptor, bool isStatic);
        Field *getField(string *name, string *descriptor, bool isStatic);
        Class *getPrimitiveClass();
        string *getName0();
        string getJavaName();

        bool isInitStarted();
        void initClass(rt::Thread *thread);

        bool isPrimitive();

        Object *getRefVar(string &field, string &descriptor);
        void setRefVar(string &field, string &descriptor, Object *ref);
        Method *getInstanceMethod(string &field, string &descriptor);

    };


}


#endif //JVM_CLASS_H
