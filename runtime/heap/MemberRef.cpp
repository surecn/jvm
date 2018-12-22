//
// Created by 郑邦国 on 2018/12/21.
//

#include "MemberRef.h"

namespace rt {

    void MemberRef::copyMemberRefInfo(cf::ConstantMemberInfo *memberInfo) {
        setClassName(memberInfo->getClassName());
        NameAndType nameAndType = memberInfo->getNameAndType();
        m_name = nameAndType.name;
        m_descriptor = nameAndType.type;
    }

}