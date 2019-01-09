//
// Created by 郑邦国 on 2018/12/6.
//

#ifndef JVM_IF_ACMP_H
#define JVM_IF_ACMP_H


#include "../base/Instruction.h"

namespace rt {

    class IF_ACMPEQ : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class IF_ACMPNE : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}

#endif //JVM_IF_ACMP_H
