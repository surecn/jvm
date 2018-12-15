//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_LSTORE_H
#define JVM_LSTORE_H


#include "../base/Instruction.h"

namespace rt {

    class LSTORE : public Index8Instruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LSTORE_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LSTORE_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LSTORE_2 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LSTORE_3 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_LSTORE_H
