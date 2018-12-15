//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_IFNONNULL_H
#define JVM_IFNONNULL_H


#include "../base/Instruction.h"

namespace rt {
    class IFNONNULL : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };
}


#endif //JVM_IFNONNULL_H
