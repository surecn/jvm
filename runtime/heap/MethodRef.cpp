//
// Created by 郑邦国 on 2018/12/21.
//

#include "MethodRef.h"

namespace rt {

    MethodRef::MethodRef(rt::ConstantPool *cp, cf::ConstantMethodRefInfo *refInfo) {
        setConstantPool(cp);
        copyMemberRefInfo(refInfo);
    }

}