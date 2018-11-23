//
// Created by 郑邦国 on 2018/11/2.
//

#include "ClassReader.h"

using namespace cls;

ClassReader::ClassReader(byte* &_data):data(_data) {
}

ClassReader::~ClassReader() {
}

u1 ClassReader::readU1() {
    u1 ch = data[0];
    data = &data[1];
    return ch;
}


u2 ClassReader::readU2() {
    u2 ch = ((u1)data[0] << 8) + ((u1)data[1]);
    data = &data[2];
    return ch;
}

u4 ClassReader::readU4() {
    unsigned int ch = ((u1)data[0]) << 24 | ((u1)data[1]) << 16 | ((u1)data[2]) << 8 | (u1)data[3];
    data = &data[4];
    return ch;
}

u8 ClassReader::readU8() {
    unsigned int ch = (((u1)data[0]) << 56) + (((u1)data[1]) << 48) + (((u1)data[2]) << 40) + (((u1)data[3]) << 32) + (((u1)data[4]) << 24) + (((u1)data[5]) << 16) + (((u1)data[6]) << 8) + ((u1)data[7]);
    data = &data[8];
    return ch;
}

u1* ClassReader::readU1s(int length) {
    u1* ch = new u1[length];
    memcpy(ch, data, length);
    data = &data[length];
    return ch;
}

u1* ClassReader::readU1s(u2 *length) {
    *length = readU2();
    return readU1s((int)*length);
}

u2* ClassReader::readU2s(int length) {
    u2 *ch = new u2[length];
    memcpy(ch, data, length * 2);
    data = &data[length * 2];
    return ch;
}

u2* ClassReader::readU2s(u2 *length) {
    *length = readU2();
    return readU2s((int)*length);
}

string ClassReader::readString() {
    u2 length = readU2();
    string s((char*)data, 0, length);
    data = &data[length];
    return s;
}