//
// Created by 郑邦国 on 2019/1/5.
//

#ifndef JVM_MULTI_ANEW_ARRAY_H
#define JVM_MULTI_ANEW_ARRAY_H


#include "../base/Instruction.h"

namespace rt {

    class MULTI_ANEW_ARRAY : public NoOperandsInstruction {
    private:
        u2 m_index;
        u1 m_dimensions;
    public:
        void fetchOperand(BytecodeReader* reader);
        void execute(Frame* frame);
    };

}


#endif //JVM_MULTI_ANEW_ARRAY_H
