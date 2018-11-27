//
// Created by 郑邦国 on 2018/11/26.
//

#ifndef JVM_DUP_H
#define JVM_DUP_H


#include "../Instruction.h"

namespace rt {

    class Dup : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class Dup_X1 : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class Dup_X2 : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class Dup2 : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class Dup2_X1 : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class Dup2_X2 : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };


}


#endif //JVM_DUP_H
