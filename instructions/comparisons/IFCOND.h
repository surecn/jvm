//
// Created by 郑邦国 on 2018/12/5.
//

#ifndef JVM_IFCOND_H
#define JVM_IFCOND_H


#include "../base/Instruction.h"

namespace rt {
    
    class IFEQ : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class IFNE : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class IFLT : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class IFLE : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class IFGT : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class IFGE : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };
}


#endif //JVM_IFCOND_H
