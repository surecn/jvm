//
// Created by 郑邦国 on 2018/12/19.
//

#include "ClassMember.h"

namespace rt {

    ClassMember * ClassMember::copyMemberInfo(cf::MemberInfo *memberInfo) {
        m_accessFlags = memberInfo->getAccessFlags();
        m_name = memberInfo->getName();
        m_descriptor = memberInfo->getDescriptor();
    }
}