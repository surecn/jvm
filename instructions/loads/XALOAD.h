//
// Created by 郑邦国 on 2019/1/5.
//

#ifndef JVM_XALOAD_H
#define JVM_XALOAD_H


#include "../base/Instruction.h"

namespace rt {

    class AALOAD : public NoOperandsInstruction{
    public:
        void execute(Frame* frame);
    };

    class BALOAD : public NoOperandsInstruction{
    public:
        void execute(Frame* frame);
    };

    class CALOAD : public NoOperandsInstruction{
    public:
        void execute(Frame* frame);
    };

    class DALOAD : public NoOperandsInstruction{
    public:
        void execute(Frame* frame);
    };

    class FALOAD : public NoOperandsInstruction{
    public:
        void execute(Frame* frame);
    };

    class IALOAD : public NoOperandsInstruction{
    public:
        void execute(Frame* frame);
    };

    class LALOAD : public NoOperandsInstruction{
    public:
        void execute(Frame* frame);
    };

    class SALOAD : public NoOperandsInstruction{
    public:
        void execute(Frame* frame);
    };

}


#endif //JVM_XALOAD_H
