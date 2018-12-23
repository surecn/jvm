//
// Created by 郑邦国 on 2018/12/19.
//

#include "Method.h"
#include "AccessFlags.h"

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
            pMethods[i]->setClass(cls);
            pMethods[i]->copyMemberInfo(memberInfo);
            pMethods[i]->copyAttributes(memberInfo);
        }
        return pMethods;
    }

    bool Method::isSynchronized() {
        return 0 != m_accessFlags & ACC_SYNCHRONIZED;
    }

    bool Method::isBridge() {
        return 0 != m_accessFlags & ACC_BRIDGE;
    }

    bool Method::isVarargs() {
        return 0 != m_accessFlags & ACC_VARARGS;
    }

    bool Method::isNative() {
        return 0 != m_accessFlags & ACC_NATIVE;
    }

    bool Method::isAbstract() {
        return 0 != m_accessFlags & ACC_ABSTRACT;
    }

    bool Method::isStrict() {
        return 0 != m_accessFlags & ACC_STRICT;
    }

    u4 Method::getMaxStack() const {
        return m_maxStack;
    }

    u4 Method::getMaxLocals() const {
        return m_maxLocals;
    }

}