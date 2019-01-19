//
// Created by 郑邦国 on 2019/1/12.
//

#ifndef JVM_JSYSTEM_H
#define JVM_JSYSTEM_H


#include "../../Registry.h"

namespace native {

    class JSystem {
    public:
        static void init();
        static void arraycopy(rt::Frame* frame);
    };

}


#endif //JVM_JSYSTEM_H
