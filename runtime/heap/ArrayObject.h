//
// Created by 郑邦国 on 2019/1/12.
//

#ifndef JVM_ARRAYOBJECT_H
#define JVM_ARRAYOBJECT_H


#include "Object.h"

namespace rt {

    class ArrayObject {
    public:
        static void ArrayCopy(Object *src, Object *dst, int srcPos, int dstPos, int length);
    };

}


#endif //JVM_ARRAYOBJECT_H
