//
// Created by 郑邦国 on 2018/11/22.
//

#include "Thread.h"

namespace rt {

    Thread::Thread() {
        strack = NULL;
    }

    Thread* Thread::newThread() {
        Thread * thread = new Thread();
        return thread;
    }
}