//
// Created by 郑邦国 on 2018/12/3.
//

#ifndef JVM_I2X_H
#define JVM_I2X_H

#include "../base/Instruction.h"

namespace rt {

    class I2B : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class I2C : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class I2S : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class I2F : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class I2D : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class I2L : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}

#endif //JVM_I2X_H
