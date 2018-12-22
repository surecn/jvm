//
// Created by 郑邦国 on 2018/12/21.
//

#ifndef JVM_FIELDREF_H
#define JVM_FIELDREF_H


#include "MemberRef.h"

namespace rt {

    class FieldRef : public MemberRef {
    private:
        Field *m_field;
    public:
        FieldRef(ConstantPool* cp, cf::ConstantFieldRefInfo *refInfo);
    };

}


#endif //JVM_FIELDREF_H
