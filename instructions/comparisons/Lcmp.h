//
// Created by 郑邦国 on 2018/12/3.
//

#ifndef JVM_LCMP_H
#define JVM_LCMP_H

#include "../base/Instruction.h"

namespace rt {

    class LCMP : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_LCMP_H
