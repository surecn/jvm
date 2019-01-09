//
// Created by 郑邦国 on 2018/12/12.
//

#ifndef JVM_MUL_H
#define JVM_MUL_H


#include "../base/Instruction.h"

namespace rt {

    class IMUL : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LMUL : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FMUL : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DMUL : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}

#endif //JVM_MUL_H
