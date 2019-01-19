//
// Created by 郑邦国 on 2019/1/5.
//

#ifndef JVM_XSTORE_H
#define JVM_XSTORE_H


#include "../base/Instruction.h"

namespace rt {

    class AASTORE : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class BASTORE : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class CASTORE : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class DASTORE : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class FASTORE : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class IASTORE : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class LASTORE : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

    class SASTORE : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

}


#endif //JVM_XSTORE_H
