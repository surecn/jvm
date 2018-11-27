//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_THREAD_H
#define JVM_THREAD_H


#include "Stack.h"

namespace rt {

    class Thread {
    private:
        int pc;
        Stack *strack;
    public:
        Thread();
        static Thread *newThread();
    };

}


#endif //JVM_THREAD_H
