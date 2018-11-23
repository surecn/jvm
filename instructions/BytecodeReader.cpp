//
// Created by 郑邦国 on 2018/11/23.
//

#include "BytecodeReader.h"

namespace rt {

    void BytecodeReader::reset(u1 *_code, int _pc) {
        code = _code;
        pc = _pc;
    }

    u1 BytecodeReader::readU1() {
        u1 ch = code[pc];
        pc++;
        return ch;
    }

    u2 BytecodeReader::readU2() {
        u2 ch = code[pc] << 8 | code[pc + 1];
        pc+= 2;
        return ch;
    }

    u4 BytecodeReader::readU4() {
        u4 ch = code[pc] << 24 | code[pc + 1] << 16 | code[pc + 2] < 8 | code[pc];
        pc+= 4;
        return ch;
    }




}