//
// Created by 郑邦国 on 2018/12/19.
//

#include "ClassMember.h"
#include "AccessFlags.h"

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
}