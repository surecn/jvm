//
// Created by 郑邦国 on 2018/11/27.
//

#ifndef JVM_MATH_H
#define JVM_MATH_H


#include "../Instruction.h"

namespace rt {

    /**
     * 求余
     */
    class DRem : public NoOperandsInstruction {
    public:
        void execute(Frame *frame);
    };

    class FRem : public NoOperandsInstruction {
    public:
        void execute(Frame *frame);
    };

    class IRem : public NoOperandsInstruction {
    public:
        void execute(Frame *frame);
    };

    class LRem : public NoOperandsInstruction {
    public:
        void execute(Frame *frame);
    };


}


#endif //JVM_MATH_H
