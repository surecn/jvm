//
// Created by 郑邦国 on 2018/12/5.
//

#ifndef JVM_ICMP_H
#define JVM_ICMP_H


#include "../base/Instruction.h"

namespace rt {
    class ICMP : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };
}



#endif //JVM_ICMP_H
