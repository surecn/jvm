//
// Created by 郑邦国 on 2019/1/9.
//

#ifndef JVM_JOBJECT_H
#define JVM_JOBJECT_H

#include "../../Registry.h"
#include "JSystem.h"


namespace native {

    class JObject {
    public:
        static void init();
        static void getClass(rt::Frame* frame);
        static void hashCode(rt::Frame* frame);
        static void clone(rt::Frame* frame);
    };

}


#endif //JVM_JOBJECT_H
