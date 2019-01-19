//
// Created by 郑邦国 on 2018/12/3.
//

#ifndef JVM_FCMP_H
#define JVM_FCMP_H


#include "../base/Instruction.h"

namespace rt {

    class FCMPG : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class FCMPL : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_FCMP_H
