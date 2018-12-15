//
// Created by 郑邦国 on 2018/12/12.
//

#ifndef JVM_DIV_H
#define JVM_DIV_H


#include "../base/Instruction.h"

namespace rt {

    class IDIV : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LDIV : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FDIV : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DDIV : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_DIV_H
