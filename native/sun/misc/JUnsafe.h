//
// Created by 郑邦国 on 2019/1/23.
//

#ifndef JVM_JUNSAFE_H
#define JVM_JUNSAFE_H

#include "../../../runtime/Frame.h"

namespace native {

    class JUnsafe {
    public:
        static void init();
        static void arrayBaseOffset(rt::Frame *frame);
        static void arrayIndexScale(rt::Frame *frame);
        static void addressSize(rt::Frame *frame);
    };

}


#endif //JVM_JUNSAFE_H
