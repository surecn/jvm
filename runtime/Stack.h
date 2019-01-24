//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_STRACK_H
#define JVM_STRACK_H

#include "../common.h"

namespace rt {
    extern class Frame;
    class Stack {
    private:
        int m_maxSize;
        int m_size;
        Frame *m_top;
    public:
        Stack(int xss);
        static Stack *newStack(int maxSize);
        void push(Frame *frame);
        Frame* pop();
        Frame* top();
        bool isEmpty();
        void clear();
        int getSize();
    };
}

#endif //JVM_STRACK_H
