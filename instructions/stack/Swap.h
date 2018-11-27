//
// Created by 郑邦国 on 2018/11/27.
//

#ifndef JVM_SWAP_H
#define JVM_SWAP_H


#include "../Instruction.h"

namespace rt {
    class Swap : public NoOperandsInstruction{
    public:
        void execute(Frame *frame);
    };
}


#endif //JVM_SWAP_H
