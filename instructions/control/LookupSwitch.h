//
// Created by 郑邦国 on 2018/12/7.
//

#ifndef JVM_LOOKUPSWITCH_H
#define JVM_LOOKUPSWITCH_H


#include "../base/Instruction.h"

namespace rt {

    class LOOKUP_SWITCH : public BranchInstruction {
    private:
        u4 defaultOffset;
        u4 npairs;
        u4* matchOffsets;
    public:
        void fetchOperand(BytecodeReader* reader);
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_LOOKUPSWITCH_H
