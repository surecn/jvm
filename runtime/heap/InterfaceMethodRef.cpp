//
// Created by 郑邦国 on 2018/12/21.
//

#include "InterfaceMethodRef.h"

namespace rt {

    InterfaceMethodRef::InterfaceMethodRef(rt::ConstantPool *cp, cf::ConstantInterfaceMethodRefInfo *refInfo) {
        setConstantPool(cp);
        copyMemberRefInfo(refInfo);
    }

}