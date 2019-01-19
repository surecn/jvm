//
// Created by 郑邦国 on 2018/12/7.
//

#ifndef JVM_WIDE_H
#define JVM_WIDE_H

#include "../base/Instruction.h"

namespace rt {

    class WIDE : public Instruction {
    private:
        Instruction *modifyInstruction;
    public:
        void fetchOperand(BytecodeReader* reader);
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_WIDE_H
