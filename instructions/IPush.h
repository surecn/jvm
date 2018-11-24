//
// Created by 郑邦国 on 2018/11/24.
//

#ifndef JVM_IPUSH_H
#define JVM_IPUSH_H

#include "Instruction.h"

namespace rt {

    class BIPUSH : public Instruction {
    private:
        char val;
    public:
        void fetchOperand(BytecodeReader* reader);
        void execute(rt::Frame* frame);
    };

    class SIPUSH : public Instruction {
    private:
        short val;
    public:
        void fetchOperand(BytecodeReader* reader);
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_IPUSH_H
