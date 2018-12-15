//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_FSTORE_H
#define JVM_FSTORE_H


#include "../base/Instruction.h"

namespace rt {

    class FSTORE : public Index8Instruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FSTORE_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FSTORE_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FSTORE_2 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FSTORE_3 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_FSTORE_H
