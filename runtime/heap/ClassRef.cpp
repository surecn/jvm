//
// Created by 郑邦国 on 2018/12/21.
//

#include "ClassRef.h"

namespace rt {

    ClassRef::ClassRef(rt::ConstantPool *cp, cf::ConstantClassInfo *classInfo) : SymRef(cp, classInfo) {
    }

}
