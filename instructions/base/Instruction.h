//
// Created by 郑邦国 on 2018/11/23.
//

#ifndef JVM_INSTRUCTION_H
#define JVM_INSTRUCTION_H

#include "../../runtime/Frame.h"
#include "BytecodeReader.h"
#include "../../runtime/Thread.h"

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
    protected:
        u2 _offset;
    public:
        void fetchOperand(BytecodeReader* reader);
        void branch(Frame *frame, int offset);
    };

    class Index8Instruction : public Instruction {
    protected:
        u1 _index;
    public:
        virtual void fetchOperand(BytecodeReader* reader);
        void setIndex(u1 index);
    };

    class Index16Instruction : public Instruction {
    protected:
        u2 _index;
    public:
        void fetchOperand(BytecodeReader* reader);
    };


}


#endif //JVM_INSTRUCTION_H
