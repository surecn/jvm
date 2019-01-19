//
// Created by 郑邦国 on 2019/1/14.
//

#ifndef JVM_JDOUBLE_H
#define JVM_JDOUBLE_H
#include "../../../runtime/Frame.h"


namespace native {

    class JDouble {
    public:
        static void init();
        static void doubleToRawLongBits(rt::Frame* frame);
        static void longBitsToDouble(rt::Frame* frame);
    };

}


#endif //JVM_JDOUBLE_H
