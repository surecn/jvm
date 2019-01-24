//
// Created by 郑邦国 on 2019/1/24.
//

#ifndef JVM_JTHREAD_H
#define JVM_JTHREAD_H


#include "../../../runtime/Frame.h"

namespace native {

    class JThread {
    public:
        static void init();
        static void currentThread(rt::Frame *frame);
    };

}



#endif //JVM_JTHREAD_H
