//
// Created by 郑邦国 on 2018/11/24.
//

#ifndef JVM_ILOAD_H
#define JVM_ILOAD_H


#include "../base/Instruction.h"

namespace rt {

    class ILOAD : public Index8Instruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ILOAD_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ILOAD_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ILOAD_2 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ILOAD_3 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_ILOAD_H
