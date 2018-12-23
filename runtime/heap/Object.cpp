//
// Created by 郑邦国 on 2018/12/22.
//

#include "Object.h"

namespace rt {

    Object::Object(rt::Class *cls, SlotArray *slotArray) {
        m_class = cls;
        m_slotArray = slotArray;
    }

    Class *Object::getClass() const {
        return m_class;
    }

    SlotArray *Object::getSlotArray() const {
        return m_slotArray;
    }

}