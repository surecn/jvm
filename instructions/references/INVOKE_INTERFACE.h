//
// Created by 郑邦国 on 2018/12/30.
//

#ifndef JVM_INVOKE_INTERFACE_H
#define JVM_INVOKE_INTERFACE_H


#include "../base/Instruction.h"

namespace rt {

    class INVOKE_INTERFACE : public Instruction {
    private:
        u4 m_index;
    public:
        void fetchOperand(BytecodeReader* reader);
        void execute(Frame* frame);
    };


}

#endif //JVM_INVOKE_INTERFACE_H
