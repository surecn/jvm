//
// Created by 郑邦国 on 2018/12/6.
//

#ifndef JVM_IFICMP_H
#define JVM_IFICMP_H

#include "../base/Instruction.h"


namespace rt {

    class IF_ICMPEQ : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class IF_ICMPNE : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class IF_ICMPLT : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class IF_ICMPLE : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class IF_ICMPGT : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class IF_ICMPGE : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_IFICMP_H
