//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_DLOAD_H
#define JVM_DLOAD_H


#include "../base/Instruction.h"

namespace rt {

    class DLOAD : public Index8Instruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DLOAD_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DLOAD_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DLOAD_2 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DLOAD_3 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_DLOAD_H
