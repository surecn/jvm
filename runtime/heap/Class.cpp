//
// Created by 郑邦国 on 2018/12/17.
//

#include "Class.h"
#include "AccessFlags.h"
#include "ConstantPool.h"
#include "ClassLoader.h"
#include "ArrayClass.h"

namespace rt{

    map<string, string>* Class::s_primitiveTypes = NULL;

    map<string, string>* Class::getPrimitiveTypes() {
        if (s_primitiveTypes == NULL) {
            s_primitiveTypes = new map<string, string>();
            (*s_primitiveTypes)["void"] = "V";
            (*s_primitiveTypes)["boolean"] = "Z";
            (*s_primitiveTypes)["byte"] = "B";
            (*s_primitiveTypes)["short"] = "S";
            (*s_primitiveTypes)["int"] = "I";
            (*s_primitiveTypes)["long"] = "J";
            (*s_primitiveTypes)["char"] = "C";
            (*s_primitiveTypes)["float"] = "F";
            (*s_primitiveTypes)["double"] = "D";
        }
        return s_primitiveTypes;
    }

    Class::Class(int accessFlags, string *name, ClassLoader *classLoader,
            bool initStarted, Class *superClass, Class **interfaces, int interfaceCount) {
        m_accessFlags = accessFlags;
        m_name = name;
        m_loader = classLoader;
        m_initStarted = initStarted;
        m_superClass = superClass;
        m_interfaces = interfaces;
        m_interfaceCount = interfaceCount;
        m_methods = NULL;
        m_methodCount = 0;
        m_fields = NULL;
        m_fieldCount = 0;
    }

    Class::Class(cf::ClassFile *cf) {
        m_initStarted = false;
        m_accessFlags = cf->getAccessFlags();
        m_name = cf->getClassName();
        m_suerClassName = cf->getSuperClassName();
        m_interfaceNames = cf->getInterfacesNames();
        m_interfaceCount = cf->getInterfaceCount();
        m_cp = new ConstantPool(this, cf->getConstantPool());
        m_fields = Field::newFields(this, cf->getFields(), cf->getFieldCount());
        m_fieldCount = cf->getFieldCount();
        m_methods = Method::newMethods(this, cf->getMethods(), cf->getMethodCount());
        m_methodCount = cf->getMethodCount();
        m_sourceFile = getSourceFile(cf);
        m_superClass = NULL;
    }

    string Class::getSourceFile(cf::ClassFile *classFile) {
        cf::SourceFileAttribute *attrs = classFile->getSourceFileAttribute();
        if (attrs != NULL) {
            return *attrs->getSourceFile();
        }
        return "Unknown";
    }

    string Class::getSourceFile() {
        return m_sourceFile;
    }

    Class::~Class() {
        delete [] m_fields;
        //delete [] m_interfaces;
        //delete [] m_interfaceNames;
        delete [] m_methods;
        delete m_staticVars;
    }

    bool Class::isPublic() {
        return (this->m_accessFlags & ACC_PUBLIC) != 0;
    }

    bool Class::isFinal() {
        return (this->m_accessFlags & ACC_FINAL) != 0;
    }

    bool Class::isSuper() {
        return (this->m_accessFlags & ACC_SUPER) != 0;
    }

    bool Class::isInterface() {
        return (this->m_accessFlags & ACC_INTERFACE) != 0;
    }

    bool Class::isAbstract() {
        return (this->m_accessFlags & ACC_ABSTRACT) != 0;
    }

    bool Class::isSynthetic() {
        return (this->m_accessFlags & ACC_SYNTHETIC) != 0;
    }

    bool Class::isAnnotation() {
        return (this->m_accessFlags & ACC_ANNOTATION) != 0;
    }

    bool Class::isEnum() {
        return (this->m_accessFlags & ACC_ENUM) != 0;
    }

    void Class::setClassLoader(rt::ClassLoader *loader) {
        m_loader = loader;
    }

    ClassLoader* Class::getClassLoader() {
        return m_loader;
    }

    string* Class::getName() {
        return m_name;
    }

    string* Class::getSuperClassName() {
        return m_suerClassName;
    }

    void Class::setSuperClass(rt::Class *cls) {
        m_superClass = cls;
    }

    Class* Class::getSuperClass() {
        return m_superClass;
    }

    string** Class::getInterfaceNames() {
        return m_interfaceNames;
    }

    u2 Class::getInterfaceCount() {
        return m_interfaceCount;
    }

    void Class::setInterfaces(rt::Class **cls) {
        m_interfaces = cls;
    }

    Class** Class::getInterfaces() {
        return m_interfaces;
    }

    java_int Class::getInstanceSlotCount() const {
        return m_instanceSlotCount;
    }

    void Class::setInstanceSlotCount(java_int instanceSlotCount) {
        Class::m_instanceSlotCount = instanceSlotCount;
    }

    java_int Class::getStaticSlotCount() const {
        return m_staticSlotCount;
    }

    void Class::setStaticSlotCount(java_int staticSlotCount) {
        Class::m_staticSlotCount = staticSlotCount;
    }

    u4 Class::getFieldCount() const {
        return m_fieldCount;
    }

    u4 Class::getMethodCount() const {
        return m_methodCount;
    }

    Field **Class::getFields() const {
        return m_fields;
    }

    Method **Class::getMethods() const {
        return m_methods;
    }

    SlotArray *Class::getStaticVars() const {
        return m_staticVars;
    }

    void Class::setStaticVars(SlotArray *staticVars) {
        Class::m_staticVars = staticVars;
    }

    ConstantPool* Class::getConstantPool() const {
        return m_cp;
    }

    string Class::getPackageName() {
        int index = m_name->rfind('/', 0);
        if (index >= 0) {
            return m_name->substr(0, index);
        }
        return "";
    }

    bool Class::isAccessibleTo(rt::Class *other) {
        return isPublic() || getPackageName() == other->getPackageName();
    }

    bool Class::isSubClassOf(rt::Class *other) {
        for (Class *c = getSuperClass();  c != NULL; c = c->getSuperClass()) {
            if (c == other) {
                return true;
            }
        }
        return false;
    }

    bool Class::isSuperClassOf(rt::Class *other) {
        return other->isSubClassOf(this);
    }

    bool Class::isAssignableFrom(rt::Class *other) {
        Class *s = other, *t = this;
        if (s == t) {
            return true;
        }
        if (!s->isArray()) {
            if (!s->isInterface()) {
                if (!t->isInterface()) {
                    return s->isSubClassOf(t);
                } else {
                    return s->isImplements(t);
                }
            } else {
                if (!t->isInterface()) {
                    return t->isJlObject();
                } else {
                    return t->isSuperInterfaceOf(s);
                }
            }
        } else {
            if (!t->isArray()) {
                if (!t->isInterface()) {
                    return t->isJlObject();
                } else {
                    return t->isJlCloneable() || t->isJioSerializable();
                }
            } else {
                Class *sc = ((ArrayClass*)s)->getComponentClass();
                Class *tc = ((ArrayClass*)t)->getComponentClass();
                return sc == tc || tc->isAssignableFrom(sc);
            }
        }
        return false;
    }

    bool Class::isImplements(Class *other) {
        for (Class *c = this;  c != NULL; c = c->getSuperClass()) {
            for (int i = 0, len = c->getInterfaceCount(); i < len; ++i) {
                Class *interface = c->getInterfaces()[i];
                if (interface == other || interface->isSubInterfaceOf(other)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool Class::isSubInterfaceOf(rt::Class *other) {
        for (int i = 0, len = this->getInterfaceCount(); i < len; ++i) {
            Class *interface = this->getInterfaces()[i];
            if (interface == other || interface->isSubInterfaceOf(other)) {
                return true;
            }
        }
        return false;
    }

    Method* Class::getMainMethod() {
        string name = "main";
        string descriptor = "([Ljava/lang/String;)V";
        return getStaticMethod(&name, &descriptor);
    }

    Method* Class::getClinitMethod() {
        string name = "<clinit>";
        string descriptor = "()V";
        return getStaticMethod(&name, &descriptor);
    }

    Method* Class::getStaticMethod(string *name, string *descriptor) {
        for (int i = 0, len = m_methodCount; i < len; ++i) {
            Method *method = m_methods[i];
            if (method->isStatic()
                && *(method->getName()) == *name
                && *method->getDescriptor() == *descriptor) {
                return method;
            }
        }
        return NULL;
    }

    ArrayClass* Class::getArrayClass() {
        string name = getArrayClassName(*Class::m_name);
        ArrayClass *cls = (ArrayClass*)getClassLoader()->loadClass(&name);
        return cls;
    }

    string Class::getArrayClassName(string className) {
        return "[" + toDescriptor(className);
    }

    string Class::toDescriptor(string className) {
        if (className[0] == '[') {
            return className;
        }
        string s = (*s_primitiveTypes)[className];
        if (s != "") {
            return s;
        }
        return "L" + className + ";";
    }

    bool Class::isArray() {
        return ((*getName())[0] == '[');
    }

    bool Class::isJlObject() {
        return *getName() == "java/lang/Object";
    }

    bool Class::isJlCloneable() {
        return *getName() == "java/lang/Cloneable";
    }

    bool Class::isJioSerializable() {
        return *getName() == "java/io/Serializable";
    }

    bool Class::isSuperInterfaceOf(Class *iface) {
        return iface->isSubInterfaceOf(this);
    }

    Method* Class::getMethod(string &name, string &descriptor, bool isStatic) {
        for (Class *cls = this; cls != NULL; cls = cls->getSuperClass()) {
            Method **pMethod = cls->getMethods();
            for (int i = 0, len = cls->getMethodCount(); i < len; ++i) {
                if (pMethod[i]->isStatic() == isStatic &&
                    *pMethod[i]->getName() == name &&
                        *pMethod[i]->getDescriptor() == descriptor) {
                    return pMethod[i];
                }
            }
        }
        return NULL;
    }

    Field* Class::getField(string &name, string &descriptor, bool isStatic) {
        for (Class *cls = this; cls != NULL; cls = cls->getSuperClass()) {
            Field **pField = cls->getFields();
            for (int i = 0, len = cls->getFieldCount(); i < len; ++i) {
                if (pField[i]->isStatic() == isStatic &&
                    *pField[i]->getName() == name &&
                    *pField[i]->getDescriptor() == descriptor) {
                    return pField[i];
                }
            }
        }
        return NULL;
    }

    Object *Class::getJClass() const {
        return m_jClass;
    }

    void Class::setJClass(Object *jClass) {
        Class::m_jClass = jClass;
    }

    string Class::getJavaName() {
        string javaName(*m_name);
        StrUtils::replace(javaName, "/", ".");
        return javaName;
    }

    bool Class::isInitStarted() {
        return m_initStarted;
    }

    void Class::startInit() {
        m_initStarted = true;
    }

    void Class::initClass(rt::Thread *thread) {
        startInit();
        scheduleClinit(thread);
        initSuperClass(thread);
    }

    void Class::scheduleClinit(rt::Thread *thread) {
        Method *clinit = getClinitMethod();
        if (clinit != NULL && clinit->getClass() == this) {
            Frame* newFrame = thread->newFrame(clinit);
            thread->pushFrame(newFrame);
        }
    }

    void Class::initSuperClass(rt::Thread *thread) {
        if (!this->isInterface()) {
            Class *superClass = this->getSuperClass();
            if (superClass != NULL && !superClass->isInitStarted()) {
                superClass->initClass(thread);
            }
        }
    }

    bool Class::isPrimitive() {
        return ((*s_primitiveTypes)[*m_name] != "");
    }

    Object* Class::getRefVar(string &fieldName, string &descriptor) {
        Field *field = getField(fieldName, descriptor, true);
        return (Object *)m_staticVars->getRef(field->getSlotId());
    }

    void Class::setRefVar(string &fieldName, string &descriptor, rt::Object *ref) {
        Field *field = getField(fieldName, descriptor, true);
        m_staticVars->setRef(field->getSlotId(), ref);
    }

    Method* Class::getInstanceMethod(string &field, string &descriptor) {
        return getMethod(field, descriptor, false);
    }

}