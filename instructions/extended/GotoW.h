//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_GOTOW_H
#define JVM_GOTOW_H


#include "../base/Instruction.h"

namespace rt {

    class GOTO_W : public BranchInstruction {
    private:
        int offset;
    public:
        void fetchOperand(BytecodeReader* reader);
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_GOTOW_H
