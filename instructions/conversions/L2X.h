//
// Created by 郑邦国 on 2018/12/3.
//

#ifndef JVM_L2X_H
#define JVM_L2X_H


#include "../base/Instruction.h"

namespace rt {

    class L2I : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class L2F : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class L2D : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}

#endif //JVM_L2X_H
