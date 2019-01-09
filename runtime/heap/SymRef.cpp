//
// Created by 郑邦国 on 2018/12/21.
//

#include "SymRef.h"
#include "ClassLoader.h"

namespace rt {

    SymRef::SymRef() {
        m_class = NULL;
    }

    void SymRef::setClassName(string *className) {
        m_className = className;
    }

    void SymRef::setConstantPool(rt::ConstantPool *constantPool) {
        m_cp = constantPool;
    }

    Class* SymRef::resolvedClass() {
        if (m_class == NULL) {
            resolveClassRef();
        }
        return m_class;
    }

    void SymRef::resolveClassRef() {
        Class *cls_d = m_cp->getClass();
        ClassLoader *classLoader = cls_d->getClassLoader();
        Class *cls_c = classLoader->loadClass(m_className);
        if (!cls_c->isAccessibleTo(cls_d)) {
            cout << "java.lang.IllegalAccessError";
        }
        m_class = cls_c;
    }

}