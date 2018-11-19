//
// Created by 郑邦国 on 2018/11/2.
//

#include "ClassReader.h"

using namespace cls;

u1 ClassReader::readU1() {
    u1 ch = data[0];
    data = &data[1];
    return ch;
}


u2 ClassReader::readU2() {
    u2 ch = data[0];
    data = &data[2];
    return ch;
}

u4 ClassReader::readU4() {
    u4 ch = data[0];
    data = &data[4];
    return ch;
}

u8 ClassReader::readU8() {
    u8 ch = data[0];
    data = &data[8];
    return ch;
}

u1* ClassReader::readU1s() {
    u2 length = readU2();
    u1* ch = &data[0];
    data = &data[length];
    return ch;
}

u2* ClassReader::readU2s() {
    u2 length = readU2();
    u2* ch = (u2*)&data[0];
    data = &data[length * 2];
    return ch;
}


