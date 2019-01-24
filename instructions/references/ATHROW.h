//
// Created by 郑邦国 on 2019/1/21.
//

#ifndef JVM_ATHROW_H
#define JVM_ATHROW_H


#include "../base/Instruction.h"

namespace rt {

    class ATHROW : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

}


#endif //JVM_ATHROW_H
