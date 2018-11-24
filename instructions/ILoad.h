//
// Created by 郑邦国 on 2018/11/24.
//

#ifndef JVM_ILOAD_H
#define JVM_ILOAD_H


#include "Instruction.h"

namespace rt {

    class ILOAD : public Index8Instruction {
    private:
        int index;
    public:
        ILOAD(int index);
        void execute(rt::Frame* frame);
    };



}


#endif //JVM_ILOAD_H
