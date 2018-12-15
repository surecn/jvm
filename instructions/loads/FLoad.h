//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_FLOAD_H
#define JVM_FLOAD_H


#include "../base/Instruction.h"

namespace rt {

    class FLOAD : public Index8Instruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FLOAD_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FLOAD_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FLOAD_2 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FLOAD_3 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_FLOAD_H
