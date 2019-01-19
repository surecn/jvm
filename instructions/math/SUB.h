//
// Created by 郑邦国 on 2018/12/12.
//

#ifndef JVM_SUB_H
#define JVM_SUB_H


#include "../base/Instruction.h"

namespace rt {

    class ISUB : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LSUB : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FSUB : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DSUB : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_SUB_H
