//
// Created by 郑邦国 on 2018/12/14.
//

#ifndef JVM_SIPUSH_H
#define JVM_SIPUSH_H


#include "../base/Instruction.h"

namespace rt {

    class SIPUSH : public Instruction {
    private:
        u2 _val;
    public:
        void fetchOperand(BytecodeReader* reader);
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_SIPUSH_H
