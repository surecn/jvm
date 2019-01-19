//
// Created by 郑邦国 on 2018/12/21.
//

#include "InterfaceMethodRef.h"
#include "MethodLookup.h"
#include "ConstantPool.h"

namespace rt {

    InterfaceMethodRef::InterfaceMethodRef(rt::ConstantPool *cp, cf::ConstantInterfaceMethodRefInfo *refInfo) {
        m_method = NULL;
        setConstantPool(cp);
        copyMemberRefInfo(refInfo);
    }

    Method* InterfaceMethodRef::resolvedInterfaceMethod() {
        if (m_method == NULL) {
            m_method = resolvedInterfaceMethodRef();
        }
        return m_method;
    }

    Method* InterfaceMethodRef::resolvedInterfaceMethodRef() {
        Class *d = m_cp->getClass();
        Class *c = resolvedClass();
        if (!c->isInterface()) {
            logError("java.lang.IncompatibleClassChangeError");
        }
        Method *method = MethodLookup::lookupInterfaceMethod(c, m_name, m_descriptor);
        if (method == NULL) {
            logError("java.lang.NoSuchMethodError");
        }
        if (!method->isAccessiableTo(d)) {
            logError("java.lang.IllegalAccessError");
        }
        m_method = method;
        return m_method;
    }



}