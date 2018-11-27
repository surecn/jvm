//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_STRACK_H
#define JVM_STRACK_H

#include "../common.h"
#include "Frame.h"

namespace rt {

    class Stack {
    private:
        int maxSize;
        int size;
        Frame *_top;
    public:
        Stack(int xss):maxSize(xss){}
        static Stack *newStack(int maxSize);
        void push(Frame *frame);
        Frame* pop();
        Frame* current();
        Frame* top();
    };
}

#endif //JVM_STRACK_H
