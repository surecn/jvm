//
// Created by 郑邦国 on 2018/11/23.
//

#ifndef JVM_INSTRUCTION_H
#define JVM_INSTRUCTION_H

#include "../runtime/Frame.h"
#include "BytecodeReader.h"

namespace rt {

    class Instruction {
    public:
        virtual void fetchOperand(BytecodeReader* reader) = 0;
        virtual void execute(rt::Frame* frame) = 0;
    };

    class NoOperandsInstruction : public Instruction {
    public:
        virtual void fetchOperand(BytecodeReader* reader);
    };

    class BranchInstruction : public Instruction {
    private:
        u2 offset;
    public:
        void fetchOperand(BytecodeReader* reader);
    };

    class Index8Instruction : public Instruction {
    private:
        u1 index;
    public:
        virtual void fetchOperand(BytecodeReader* reader);
    };

    class Index16Instruction : public Instruction {
    private:
        u2 index;
    public:
        void fetchOperand(BytecodeReader* reader);
    };


}


#endif //JVM_INSTRUCTION_H
