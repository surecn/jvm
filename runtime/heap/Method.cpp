//
// Created by 郑邦国 on 2018/12/19.
//

#include "Method.h"

namespace rt {


    void Method::copyAttributes(cf::MemberInfo *memberInfo) {
        cf::CodeAttribute *codeAttribute = memberInfo->getCodeAttribute();
        if (codeAttribute != NULL) {
            m_maxStack = codeAttribute->getMaxStack();
            m_maxLocals = codeAttribute->getMaxLocals();
            m_code = codeAttribute->getCode();
        }
    }

    Method** Method::newMethods(rt::Class *cls, cf::MemberInfo **cfMembers, int count) {
        Method **pMethods = new Method*[count];
        for (int i = 0; i < count; ++i) {
            cf::MemberInfo *memberInfo = cfMembers[i];
            pMethods[i] = new Method();
            pMethods[i]->_cls = cls;
            pMethods[i]->copyMemberInfo(memberInfo);
            pMethods[i]->copyAttributes(memberInfo);
        }
        return pMethods;
    }



}