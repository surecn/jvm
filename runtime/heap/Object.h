//
// Created by 郑邦国 on 2018/12/22.
//

#ifndef JVM_OBJECT_H
#define JVM_OBJECT_H

#include "../../common/SlotArray.h"
#include "Class.h"

namespace rt {

    class Object {
    private:
        Class *cls;
        SlotArray *slotArray;

    };


}

#endif //JVM_OBJECT_H
