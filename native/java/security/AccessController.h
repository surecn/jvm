//
// Created by 郑邦国 on 2019/1/23.
//

#ifndef JVM_ACCESSCONTROLLER_H
#define JVM_ACCESSCONTROLLER_H

#include "../../../runtime/Frame.h"

namespace native {

    class AccessController {
    private:
    public:
        static void init();
        static void doPrivileged(rt::Frame *frame);

    };
}


#endif //JVM_ACCESSCONTROLLER_H
