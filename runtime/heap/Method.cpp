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
        return m_accessFlags & ACC_SYNCHRONIZED != 0;
    }

    bool Method::isBridge() {
        return m_accessFlags & ACC_BRIDGE != 0;
    }

    bool Method::isVarargs() {
        return m_accessFlags & ACC_VARARGS != 0;
    }

    bool Method::isNative() {
        return m_accessFlags & ACC_NATIVE != 0;
    }

    bool Method::isAbstract() {
        return m_accessFlags & ACC_ABSTRACT != 0;
    }

    bool Method::isStrict() {
        return m_accessFlags & ACC_STRICT != 0;
    }

    u4 Method::getMaxStack() const {
        return m_maxStack;
    }

    u4 Method::getMaxLocals() const {
        return m_maxLocals;
    }

    u1* Method::getCode() {
        return m_code;
    }

}