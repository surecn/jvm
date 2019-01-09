//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_DSTORE_H
#define JVM_DSTORE_H


#include "../base/Instruction.h"

namespace rt {

    class DSTORE : public Index8Instruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DSTORE_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DSTORE_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DSTORE_2 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DSTORE_3 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}

#endif //JVM_DSTORE_H
