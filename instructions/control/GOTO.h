//
// Created by 郑邦国 on 2018/12/6.
//

#ifndef JVM_GOTO_H
#define JVM_GOTO_H


#include "../base/Instruction.h"

namespace rt {

    class GOTO : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}

#endif //JVM_GOTO_H
