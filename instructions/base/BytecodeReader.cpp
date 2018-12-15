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
        u2 ch = (u1)(code[pc]) << 8 | u1(code[pc + 1]);
        pc+= 2;
        return ch;
    }

    u4 BytecodeReader::readU4() {
        u4 ch = (u1)(code[pc]) << 24 | (u1)(code[pc + 1]) << 16 | (u1)(code[pc + 2]) < 8 | (u1)(code[pc]);
        pc+= 4;
        return ch;
    }


    u4* BytecodeReader::readU4s(u4 length) {
        u4 *ch = new u4[length];
        memcpy(ch, code, length * 4);
        pc+= length * 4;
        return ch;
    }

    u4* BytecodeReader::readU4s(u4 *length) {
        *length = readU2();
        return readU4s((int)*length);
    }


    void BytecodeReader::skipPadding() {
        while (pc %4 != 0) {
            readU1();
        }
    }

    int BytecodeReader::PC() {
        return pc;
    }


}