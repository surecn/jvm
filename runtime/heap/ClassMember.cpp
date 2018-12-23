//
// Created by 郑邦国 on 2018/12/19.
//

#include "ClassMember.h"
#include "AccessFlags.h"
#include "Class.h"

namespace rt {

    bool ClassMember::isPublic() {
        return 0 != m_accessFlags & ACC_PUBLIC;
    }

    bool ClassMember::isPrivate() {
        return 0 != m_accessFlags & ACC_PRIVATE;
    }

    bool ClassMember::isProtected() {
        return 0 != m_accessFlags & ACC_PROTECTED;
    }

    bool ClassMember::isStatic() {
        return 0 != m_accessFlags & ACC_STATIC;
    }

    bool ClassMember::isFinal() {
        return  0 != m_accessFlags & ACC_FINAL;
    }

    bool ClassMember::isSynthetic() {
        return 0 != m_accessFlags & ACC_SYNTHETIC;
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