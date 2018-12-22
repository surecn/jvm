//
// Created by 郑邦国 on 2018/12/19.
//

#ifndef JVM_FIELD_H
#define JVM_FIELD_H


#include "ClassMember.h"

namespace rt {

    class Field : public ClassMember{

    public:
        Field **newFields(Class *cls, cf::MemberInfo **cfFields, int count);
    };

}


#endif //JVM_FIELD_H
