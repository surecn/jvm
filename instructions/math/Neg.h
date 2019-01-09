//
// Created by 郑邦国 on 2018/12/12.
//

#ifndef JVM_NEG_H
#define JVM_NEG_H


#include "../base/Instruction.h"

namespace rt {

    class INEG : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LNEG : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FNEG : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DNEG : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_NEG_H
