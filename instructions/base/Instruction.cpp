//
// Created by 郑邦国 on 2018/11/23.
//

#include "Instruction.h"

namespace rt {

    void NoOperandsInstruction::fetchOperand(BytecodeReader *reader) {

    }

    void BranchInstruction::fetchOperand(BytecodeReader *reader) {
        m_offset = (int)reader->readC2();
    }

    void BranchInstruction::branch(rt::Frame *frame, int offset) {
        Thread* thread = frame->getThread();
        int pc = thread->getPC();
        int nextPc = pc + offset;
        frame->setNextPc(nextPc);
    }

    void Index8Instruction::fetchOperand(BytecodeReader *reader) {
        m_index = reader->readU1();
    }

    void Index8Instruction::setIndex(u1 index) {
        m_index = index;
    }

    void Index16Instruction::fetchOperand(BytecodeReader *reader) {
        m_index = reader->readU2();
    }


}