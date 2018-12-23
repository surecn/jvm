//
// Created by 郑邦国 on 2018/12/17.
//

#include "Class.h"
#include "AccessFlags.h"

namespace rt{

    Class::Class(cf::ClassFile *cf) {
        m_accessFlags = cf->getAccessFlags();
        m_name = cf->getClassName();
        m_suerClassName = cf->getSuperClassName();
        m_interfaceNames = cf->getInterfacesNames();
        m_interfaceCount = cf->getInterfaceCount();
        m_cp = new ConstantPool(this, cf->getConstantPool());
        m_fields = Field::newFields(this, cf->getFields(), cf->getFieldCount());
        m_method = Method::newMethods(this, cf->getMethods(), cf->getMethodCount());
    }

    bool Class::isPublic() {
        return 0 != this->m_accessFlags & ACC_PUBLIC;
    }

    bool Class::isFinal() {
        return 0 != this->m_accessFlags & ACC_FINAL;
    }

    bool Class::isSuper() {
        return 0 != this->m_accessFlags & ACC_SUPER;
    }

    bool Class::isInterface() {
        return 0 != this->m_accessFlags & ACC_INTERFACE;
    }

    bool Class::isAbstract() {
        return 0 != this->m_accessFlags & ACC_ABSTRACT;
    }

    bool Class::isSynthetic() {
        return 0 != this->m_accessFlags & ACC_SYNTHETIC;
    }

    bool Class::isAnnotation() {
        return 0 != this->m_accessFlags & ACC_ANNOTATION;
    }

    bool Class::isEnum() {
        return 0 != this->m_accessFlags & ACC_ENUM;
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

    Method **Class::getMethod() const {
        return m_method;
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

    Object* Class::newObject() {
        return new Object(this, new SlotArray(m_instanceSlotCount));
    }

    bool Class::isAssignableFrom(rt::Class *other) {
        if (this == other) {
            return true;
        }
        if (this->isInterface()) {
            return other->isSubClassOf(this);
        } else {
            return other->isImplements(this);
        }
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

}