//
// Created by 郑邦国 on 2019/1/9.
//

#ifndef JVM_JCLASS_H
#define JVM_JCLASS_H


#include "../../Registry.h"

namespace native {

    class JClass {
    private:
    public:
        static void init();
        static void getPrimitiveClass(rt::Frame *frame);
        static void getName0(rt::Frame *frame);
        static void desiredAssertionStatus0(rt::Frame *frame);
        static void getComponentType(rt::Frame *frame);


    };
}


#endif //JVM_JCLASS_H
