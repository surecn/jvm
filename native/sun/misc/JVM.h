//
// Created by 郑邦国 on 2019/1/18.
//

#ifndef JVM_VM_H
#define JVM_VM_H


#include "../../../runtime/Frame.h"

namespace native {

    class JVM {
    public:
        static void init();
        static void initialize(rt::Frame *frame);
    };

}


#endif //JVM_VM_H
