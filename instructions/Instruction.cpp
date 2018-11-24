//
// Created by 郑邦国 on 2018/11/23.
//

#include "Instruction.h"

namespace rt {

    void NoOperandsInstruction::fetchOperand(BytecodeReader *reader) {

    }

    void BranchInstruction::fetchOperand(BytecodeReader *reader) {
        offset = reader->readU2();
    }


    void Index8Instruction::fetchOperand(BytecodeReader *reader) {
        index = reader->readU1();
    }

    void Index16Instruction::fetchOperand(BytecodeReader *reader) {
        index = reader->readU2();
    }


}