//
// Created by 郑邦国 on 2018/12/6.
//

#ifndef JVM_TABLESWITCH_H
#define JVM_TABLESWITCH_H


#include "../base/Instruction.h"

namespace rt {
    class TABLE_SWITCH : public BranchInstruction {
    private:
        java_int defaultOffset;
        java_int low;
        java_int high;
        u4 *jumpOffsets;
    public:
        void fetchOperand(BytecodeReader* reader);
        void execute(Frame* frame);
    };

}

#endif //JVM_TABLESWITCH_H
