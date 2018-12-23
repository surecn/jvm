//
// Created by 郑邦国 on 2018/12/22.
//

#ifndef JVM_OBJECT_H
#define JVM_OBJECT_H

#include "../../common/SlotArray.h"

namespace rt {
    extern class Class;
    class Object {
    private:
        Class *m_class;
        SlotArray *m_slotArray;
    public:
        Object(Class *cls, SlotArray *slotArray);

        Class *getClass() const;

        SlotArray *getSlotArray() const;
    };


}

#endif //JVM_OBJECT_H
