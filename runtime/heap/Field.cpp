//
// Created by 郑邦国 on 2018/12/19.
//

#include "Field.h"

namespace rt {

    Field** Field::newFields(rt::Class *cls, cf::MemberInfo **cfFields, int count) {
        Field **fields = new Field*[count];
        for (int i = 0; i < count; ++i) {
            cf::MemberInfo *memberInfo = cfFields[i];
            fields[i] = new Field();
            fields[i]->_cls = cls;
            fields[i]->copyMemberInfo(cfFields[i]);
        }
        return fields;
    }

}