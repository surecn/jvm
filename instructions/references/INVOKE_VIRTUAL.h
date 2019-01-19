//
// Created by 郑邦国 on 2018/12/26.
//

#ifndef JVM_INVOKE_VIRTUAL_H
#define JVM_INVOKE_VIRTUAL_H


#include "../base/Instruction.h"

namespace rt {

    class INVOKE_VIRTUAL : public Index16Instruction {
    public:
        void execute(Frame* frame);
        void println(OperandStack *stack, string *descriptor);
    };

}


#endif //JVM_INVOKE_VIRTUAL_H
