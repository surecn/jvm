//
// Created by 郑邦国 on 2018/12/11.
//

#ifndef JVM_ADD_H
#define JVM_ADD_H


#include "../base/Instruction.h"

namespace rt {

    class IADD : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FADD : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DADD : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LADD : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_ADD_H
