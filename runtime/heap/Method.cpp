//
// Created by 郑邦国 on 2018/12/19.
//

#include "Method.h"
#include "AccessFlags.h"
#include "MethodDescriptor.h"
#include "ConstantPool.h"

namespace rt {

    Method::Method() {
        m_argSlotCount = 0;
    }

    void Method::copyAttributes(cf::MemberInfo *memberInfo) {
        cf::CodeAttribute *codeAttribute = memberInfo->getCodeAttribute();
        if (codeAttribute != NULL) {
            m_maxStack = codeAttribute->getMaxStack();
            m_maxLocals = codeAttribute->getMaxLocals();
            m_code = codeAttribute->getCode();
            m_lineNumberTable = codeAttribute->getLineNumberTableAttribute();
            m_exceptionTable = new ExceptionTable(codeAttribute->getExceptionTable(), codeAttribute->getExceptionTableLength(), getClass()->getConstantPool());
        }
    }

    void Method::calcArgSlotCount(const vector<char> paramTypes) {
        for (int i = 0, len = paramTypes.size(); i < len; ++i) {
            char ch = paramTypes[i];
            m_argSlotCount++;
            if (ch == 'J' || ch == 'D') {
                m_argSlotCount++;
            }
        }
        if (!isStatic()) {
            m_argSlotCount++;
        }
    }

    Method** Method::newMethods(rt::Class *cls, cf::MemberInfo **cfMembers, int count) {
        MethodDescriptorParser methodDescriptorParser;
        Method **pMethods = new Method*[count];
        for (int i = 0; i < count; ++i) {
            cf::MemberInfo *memberInfo = cfMembers[i];
            pMethods[i] = new Method();
            pMethods[i]->setClass(cls);
            pMethods[i]->copyMemberInfo(memberInfo);
            pMethods[i]->copyAttributes(memberInfo);
            MethodDescriptor *methodDescriptor = methodDescriptorParser.parseMethodDescriptor(pMethods[i]->getDescriptor());
            pMethods[i]->calcArgSlotCount(methodDescriptor->getParamaterType());
            if (pMethods[i]->isNative()) {
                pMethods[i]->injectCodeAttribute(methodDescriptor->getReturnType());
            }
            delete methodDescriptor;
            methodDescriptorParser.reset();
        }
        return pMethods;
    }

    bool Method::isSynchronized() {
        return (m_accessFlags & ACC_SYNCHRONIZED) != 0;
    }

    bool Method::isBridge() {
        return (m_accessFlags & ACC_BRIDGE) != 0;
    }

    bool Method::isVarargs() {
        return (m_accessFlags & ACC_VARARGS) != 0;
    }

    bool Method::isNative() {
        return (m_accessFlags & ACC_NATIVE) != 0;
    }

    bool Method::isAbstract() {
        return (m_accessFlags & ACC_ABSTRACT) != 0;
    }

    bool Method::isStrict() {
        return (m_accessFlags & ACC_STRICT) != 0;
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

    u4 Method::getArgSlotCount() {
        return m_argSlotCount;
    }

    void Method::injectCodeAttribute(char returnType) {
        m_maxStack = 4;
        m_maxLocals = m_argSlotCount;
        switch (returnType) {
            case 'V':
                m_code = new byte[2]{0xfe, 0xb1};//return
                break;
            case 'D':
                m_code = new byte[2]{0xfe, 0xaf};//dreturn
                break;
            case 'F':
                m_code = new byte[2]{0xfe, 0xae};//rreturn
                break;
            case 'J':
                m_code = new byte[2]{0xfe, 0xad};//lreturn
                break;
            case 'L':
            case '[':
                m_code = new byte[2]{0xfe, 0xb0};//areturn
                break;
            default:
                m_code = new byte[2]{0xfe, 0xac};//ireturn
                break;
        }
    }

    int Method::findExceptionHandler(rt::Class *exClass, int pc) {
        ExceptionHandler * handler = m_exceptionTable->findExceptionHandler(exClass, pc);
        if (handler != NULL) {
            return handler->handlerPC;
        }
        return -1;
    }

    int Method::getLineNumber(int pc) {
        if (isNative()) {
            return -2;
        }
        if (m_lineNumberTable == NULL) {
            return -1;
        }
        return m_lineNumberTable->getLineNumber(pc);
    }
}