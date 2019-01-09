//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_ASTORE_H
#define JVM_ASTORE_H


#include "../base/Instruction.h"

namespace rt {

    class ASTORE : public Index8Instruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ASTORE_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ASTORE_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ASTORE_2 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ASTORE_3 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_ASTORE_H
