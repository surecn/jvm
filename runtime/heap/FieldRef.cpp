//
// Created by 郑邦国 on 2018/12/21.
//

#include "FieldRef.h"

namespace rt {

    FieldRef::FieldRef(rt::ConstantPool *cp, cf::ConstantFieldRefInfo *refInfo) {
        setConstantPool(cp);
        copyMemberRefInfo(refInfo);
    }

}
