//
// Created by 郑邦国 on 2018/12/12.
//

#ifndef JVM_XOR_H
#define JVM_XOR_H


#include "../base/Instruction.h"

namespace rt {

    class IXOR : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LXOR : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_XOR_H
