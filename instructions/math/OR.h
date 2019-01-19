//
// Created by 郑邦国 on 2018/12/12.
//

#ifndef JVM_OR_H
#define JVM_OR_H


#include "../base/Instruction.h"

namespace rt {

    class IOR : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class LOR : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_OR_H
