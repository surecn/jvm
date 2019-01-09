//
// Created by 郑邦国 on 2018/12/21.
//

#include "ClassRef.h"
#include "ClassLoader.h"

namespace rt {

    ClassRef::ClassRef(rt::ConstantPool *cp, cf::ConstantClassInfo *classInfo) {
        setConstantPool(cp);
        m_className = classInfo->getName();
    }

}
