//
// Created by 郑邦国 on 2018/12/23.
//

#ifndef JVM_LDC_H
#define JVM_LDC_H


#include "../base/Instruction.h"

namespace rt {

    class LDC : Index16Instruction {
    public:
        void execute(Frame* frame);
    };

    class LDC_W : Index16Instruction {
    public:
        void execute(Frame* frame);
    };

    class LDC2_W : Index16Instruction {
    public:
        void execute(Frame* frame);
    };
}


#endif //JVM_LDC_H
