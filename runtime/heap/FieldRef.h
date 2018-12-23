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
        void resolveFieldRef();
        Field *lookupField(Class *cls, string *name, string *descriptor);
    public:
        FieldRef(ConstantPool* cp, cf::ConstantFieldRefInfo *refInfo);
        Field *resolvedField();
    };

}


#endif //JVM_FIELDREF_H
