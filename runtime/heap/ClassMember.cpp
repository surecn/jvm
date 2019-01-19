//
// Created by 郑邦国 on 2018/12/19.
//

#include "ClassMember.h"
#include "AccessFlags.h"
#include "Class.h"

namespace rt {

    bool ClassMember::isPublic() {
        return (m_accessFlags & ACC_PUBLIC) != 0;
    }

    bool ClassMember::isPrivate() {
        return (m_accessFlags & ACC_PRIVATE) != 0;
    }

    bool ClassMember::isProtected() {
        return (m_accessFlags & ACC_PROTECTED) != 0;
    }

    bool ClassMember::isStatic() {
        return (m_accessFlags & ACC_STATIC) != 0;
    }

    bool ClassMember::isFinal() {
        return (m_accessFlags & ACC_FINAL) != 0;
    }

    bool ClassMember::isSynthetic() {
        return (m_accessFlags & ACC_SYNTHETIC) != 0;
    }

    string *ClassMember::getDescriptor() const {
        return m_descriptor;
    }

    void ClassMember::copyMemberInfo(cf::MemberInfo *memberInfo) {
        m_accessFlags = memberInfo->getAccessFlags();
        m_name = memberInfo->getName();
        m_descriptor = memberInfo->getDescriptor();
    }

    string *ClassMember::getName() const {
        return m_name;
    }

    bool ClassMember::isAccessiableTo(rt::Class *cls_d) {
        if (isPublic()) {
            return true;
        }
        Class *cls_c = m_class;
        if (isProtected()) {
            return cls_d == cls_c || cls_d->isSubClassOf(cls_c) || cls_c->getPackageName() == cls_d->getPackageName();
        }
        if (!isPrivate()) {
            return cls_c->getPackageName() == cls_d->getPackageName();
        }
        return cls_d == cls_c;
    }

    Class *ClassMember::getClass() const {
        return m_class;
    }

    void ClassMember::setClass(Class *cls) {
        ClassMember::m_class = cls;
    }

}