//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_LLOAD_H
#define JVM_LLOAD_H


#include "../base/Instruction.h"

namespace rt {

    class LLOAD : public Index8Instruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LLOAD_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LLOAD_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LLOAD_2 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LLOAD_3 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_LLOAD_H
