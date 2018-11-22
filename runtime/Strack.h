//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_STRACK_H
#define JVM_STRACK_H

#include "../common.h"
#include "Frame.h"

namespace rt {

    class Strack {
    private:
        int maxSize;
        int size;
        Frame *_top;
    public:
        Strack(int xss):maxSize(xss){}
        static Strack *newStrack(int maxSize);
        void push(Frame *frame);
        Frame* pop();
        Frame* current();
        Frame* top();
    };
}

#endif //JVM_STRACK_H
