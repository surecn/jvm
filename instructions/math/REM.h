//
// Created by 郑邦国 on 2018/11/27.
//

#ifndef JVM_MATH_H
#define JVM_MATH_H


#include "../base/Instruction.h"

namespace rt {

    /**
     * 求余
     */
    class DREM : public NoOperandsInstruction {
    public:
        void execute(Frame *frame);
    };

    class FREM : public NoOperandsInstruction {
    public:
        void execute(Frame *frame);
    };

    class IREM : public NoOperandsInstruction {
    public:
        void execute(Frame *frame);
    };

    class LREM : public NoOperandsInstruction {
    public:
        void execute(Frame *frame);
    };


}


#endif //JVM_MATH_H
