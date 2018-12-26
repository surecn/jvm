//
// Created by 郑邦国 on 2018/12/21.
//

#include "MemberRef.h"

namespace rt {

    void MemberRef::copyMemberRefInfo(cf::ConstantMemberInfo *memberInfo) {
        m_className = memberInfo->getClassName();
        NameAndType nameAndType = memberInfo->getNameAndType();
        m_name = nameAndType.name;
        m_descriptor = nameAndType.type;
    }

    string* MemberRef::getName() {
        return m_name;
    }

    string* MemberRef::getDescriptor() {
        return m_descriptor;
    }

}