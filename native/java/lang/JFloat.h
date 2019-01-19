//
// Created by 郑邦国 on 2019/1/13.
//

#ifndef JVM_JFLOAT_H
#define JVM_JFLOAT_H


#include "../../../runtime/Frame.h"

namespace native {

    class JFloat {
    public:
        static void init();
        static void floatToRawIntBits(rt::Frame* frame);
    };

}


#endif //JVM_JFLOAT_H
