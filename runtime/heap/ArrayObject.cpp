//
// Created by 郑邦国 on 2019/1/12.
//

#include "ArrayObject.h"
#include "Class.h"

namespace rt {

    void ArrayObject::ArrayCopy(rt::Object *src, rt::Object *dst, int srcPos, int dstPos, int length) {
        string *clsName = src->getClass()->getName();

        int typeSize = 0;
        if (*clsName == "[Z") {
            typeSize = sizeof(java_bool);
        } else if (*clsName == "[B") {
            typeSize = sizeof(java_byte);
        } else if (*clsName == "[C") {
            typeSize = sizeof(java_char);
        } else if (*clsName == "[S") {
            typeSize = sizeof(java_short);
        } else if (*clsName == "[I") {
            typeSize = sizeof(java_int);
        } else if (*clsName == "[J") {
            typeSize = sizeof(java_long);
        } else if (*clsName == "[F") {
            typeSize = sizeof(java_float);
        } else if (*clsName == "[D") {
            typeSize = sizeof(java_double);
        } else {
            typeSize = sizeof(void*);
        }
        void * s = src->getData();
        char * n_src = (char *)src->getData();
        char * n_dst = (char *)dst->getData();
        memcpy(n_src + srcPos * typeSize, n_dst + dstPos * typeSize, typeSize * length);
    }

}