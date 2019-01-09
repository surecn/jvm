//
// Created by 郑邦国 on 2018/11/23.
//

#ifndef JVM_CONSTANT_H
#define JVM_CONSTANT_H


#include "../base/Instruction.h"

namespace rt {

    class Constant {
    private:

    };

    class NOP : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ACONST_NULL : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DCONST_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DCONST_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FCONST_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FCONST_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FCONST_2 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ICONST_M1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ICONST_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ICONST_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ICONST_2 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ICONST_3 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ICONST_4 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ICONST_5 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LCONST_0 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LCONST_1 : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}

#endif //JVM_CONSTANT_H
