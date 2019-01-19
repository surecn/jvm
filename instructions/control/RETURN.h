//
// Created by 郑邦国 on 2018/12/30.
//

#ifndef JVM_RETURN_H
#define JVM_RETURN_H


#include "../base/Instruction.h"

namespace rt {

    class RETURN : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class ARETURN : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class IRETURN : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class LRETURN : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class FRETURN : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class DRETURN : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

}


#endif //JVM_RETURN_H
