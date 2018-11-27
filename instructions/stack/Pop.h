//
// Created by 郑邦国 on 2018/11/26.
//

#ifndef JVM_POP_H
#define JVM_POP_H

#include "../Instruction.h"

namespace rt {
    class Pop : public NoOperandsInstruction {
    private:
    public:
        void execute(Frame* frame);
    };

    class Pop2 : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

}

#endif //JVM_POP_H
