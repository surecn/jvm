//
// Created by 郑邦国 on 2018/12/21.
//

#include "MethodRef.h"
#include "MethodLookup.h"
#include "ConstantPool.h"

namespace rt {

    MethodRef::MethodRef(rt::ConstantPool *cp, cf::ConstantMethodRefInfo *refInfo) {
        m_method = NULL;
        setConstantPool(cp);
        copyMemberRefInfo(refInfo);
    }

    Method* MethodRef::resolvedMethod() {
        if (m_method == NULL) {
            resolvedMethodRef();
        }
        return m_method;
    }

    void MethodRef::resolvedMethodRef() {
        Class *d = m_cp->getClass();
        Class *c = resolvedClass();
        if (c->isInterface()) {
            logError("java.lang.IncompatibleClassChangeError");
        }
        Method *method = lookupMethod(c, m_name, m_descriptor);
        if (method == NULL) {
            logError("java.lang.NoSuchMethodError");
        }
        if (!method->isAccessiableTo(d)) {
            logError("java.lang.IllegalAccessError");
        }
        m_method = method;
    }

    Method* MethodRef::lookupMethod(rt::Class *cls, string *name, string *descriptor) {
        Method *method = MethodLookup::lookupMethodInClass(cls, name, descriptor);
        if (method == NULL) {
            method = MethodLookup::lookupMethodInInterfaces(cls->getInterfaces(), cls->getInterfaceCount(), name, descriptor);
        }
        return method;
    }







}