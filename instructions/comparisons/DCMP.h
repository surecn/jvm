//
// Created by 郑邦国 on 2018/12/5.
//

#ifndef JVM_DCMP_H
#define JVM_DCMP_H


#include "../base/Instruction.h"

namespace rt {

    class DCMPG : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class DCMPL : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_DCMP_H
