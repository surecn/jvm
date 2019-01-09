//
// Created by 郑邦国 on 2018/12/19.
//

#ifndef JVM_FIELD_H
#define JVM_FIELD_H


#include "ClassMember.h"

namespace rt {

    class Field : public ClassMember{
    private:
        u4 m_slotId;
        u4 m_constValueIndex;
    public:
        static Field **newFields(Class *cls, cf::MemberInfo **cfFields, int count);
        bool isVolatile();
        bool isTransient();
        bool isEnum();
        bool isLongOrDouble();
        u4 getSlotId() const;
        void setSlotId(u4 slotId);
        void copyAttributes(cf::MemberInfo *memberInfo);
        u4 getConstValueIndex() const;
    };
}


#endif //JVM_FIELD_H
