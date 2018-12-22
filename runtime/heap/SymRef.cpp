//
// Created by 郑邦国 on 2018/12/21.
//

#include "SymRef.h"

namespace rt {

    SymRef::SymRef(rt::ConstantPool *cp, cf::ConstantClassInfo *classInfo) : m_cp(cp), m_className(classInfo->getName()) {
    }

    void SymRef::setClassName(string *className) {
        m_className = className;
    }

    void SymRef::setConstantPool(rt::ConstantPool *constantPool) {
        m_cp = constantPool;
    }

}