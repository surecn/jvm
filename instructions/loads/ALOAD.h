//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_ALOAD_H
#define JVM_ALOAD_H


#include "../base/Instruction.h"

namespace rt {

    class ALOAD : public Index8Instruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ALOAD_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ALOAD_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ALOAD_2 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ALOAD_3 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_ALOAD_H
