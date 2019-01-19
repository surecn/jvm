//
// Created by 郑邦国 on 2018/12/3.
//

#ifndef JVM_D2X_H
#define JVM_D2X_H

#include "../base/Instruction.h"

namespace rt {
    class D2F : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class D2I : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class D2L : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_D2X_H
