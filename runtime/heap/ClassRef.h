//
// Created by 郑邦国 on 2018/12/21.
//

#ifndef JVM_CLASSREF_H
#define JVM_CLASSREF_H


#include "SymRef.h"
#include "../../classfile/ConstantClassInfo.h"

namespace rt {

    class ClassRef : public SymRef {
    private:
    public:
        ClassRef(ConstantPool *cp, cf::ConstantClassInfo *classInfo);

    };

}


#endif //JVM_CLASSREF_H
