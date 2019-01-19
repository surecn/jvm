//
// Created by 郑邦国 on 2018/12/3.
//

#ifndef JVM_F2X_H
#define JVM_F2X_H

#include "../base/Instruction.h"

namespace rt {

    class F2I : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class F2L : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class F2D : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}

#endif //JVM_F2X_H
