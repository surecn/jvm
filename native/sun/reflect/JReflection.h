//
// Created by 郑邦国 on 2019/1/23.
//

#ifndef JVM_JREFLECTION_H
#define JVM_JREFLECTION_H

#include "../../../runtime/Frame.h"

namespace native {

    class JReflection {
    private:
    public:
        static void init();
        static void getCallerClass(rt::Frame *frame);

    };
}

#endif //JVM_JREFLECTION_H
