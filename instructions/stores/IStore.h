//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_ISTORE_H
#define JVM_ISTORE_H


#include "../base/Instruction.h"

namespace rt {

    class ISTORE : public Index8Instruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ISTORE_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ISTORE_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ISTORE_2 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ISTORE_3 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_ISTORE_H
