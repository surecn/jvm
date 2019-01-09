//
// Created by 郑邦国 on 2018/11/2.
//

#include "ClassReader.h"

<<<<<<< HEAD
<<<<<<< HEAD
using namespace cls;

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
    unsigned int ch = (((u1)data[0]) << 24) + (((u1)data[1]) << 16) + (((u1)data[2]) << 8) + ((u1)data[3]);
    data = &data[4];
    return ch;
}

u8 ClassReader::readU8() {
    unsigned int ch = (((u1)data[0]) << 56) + (((u1)data[1]) << 48) + (((u1)data[2]) << 40) + (((u1)data[3]) << 32) + (((u1)data[4]) << 24) + (((u1)data[5]) << 16) + (((u1)data[6]) << 8) + ((u1)data[7]);
    data = &data[8];
    return ch;
}

u1* ClassReader::readU1s(int length) {
    u1* ch = (u1*)data;
    data = &data[length];
    return ch;
}

u1* ClassReader::readU1s() {
    u2 length = readU2();
    u1* ch = (u1*)&data[0];
    data = &data[length];
    return ch;
}

u2* ClassReader::readU2s() {
    u2 length = readU2();
    u2* ch = (u2*)&data[0];
    data = &data[length * 2];
    return ch;
}
=======
namespace cf {
    ClassReader::ClassReader(byte* &_data):m_data(_data) {
    }
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e

    u1 ClassReader::readU1() {
        u1 ch = m_data[0];
        m_data = &m_data[1];
        return ch;
    }


    u2 ClassReader::readU2() {
        u2 ch = ((u1)m_data[0] << 8) + ((u1)m_data[1]);
        m_data = &m_data[2];
        return ch;
    }

    u4 ClassReader::readU4() {
        unsigned int ch = ((u1)m_data[0]) << 24 | ((u1)m_data[1]) << 16 | ((u1)m_data[2]) << 8 | (u1)m_data[3];
        m_data = &m_data[4];
        return ch;
    }

    u8 ClassReader::readU8() {
        unsigned int ch = (((u1)m_data[0]) << 56) + (((u1)m_data[1]) << 48) + (((u1)m_data[2]) << 40) + (((u1)m_data[3]) << 32) + (((u1)m_data[4]) << 24) + (((u1)m_data[5]) << 16) + (((u1)m_data[6]) << 8) + ((u1)m_data[7]);
        m_data = &m_data[8];
        return ch;
    }

    u1* ClassReader::readU1s(int length) {
        u1* ch = new u1[length];
        memcpy(ch, m_data, length);
        m_data = &m_data[length];
        return ch;
    }

    u1* ClassReader::readU1s(u2 *length) {
        *length = readU2();
        return readU1s((int)*length);
    }

    u2* ClassReader::readU2s(int length) {
        u2 *ch = new u2[length];
        memcpy(ch, m_data, length * 2);
        m_data = &m_data[length * 2];
        return ch;
    }

    u2* ClassReader::readU2s(u2 *length) {
        *length = readU2();
        return readU2s((int)*length);
    }

=======
namespace cf {
    ClassReader::ClassReader(byte* &_data):m_data(_data) {
    }

    u1 ClassReader::readU1() {
        u1 ch = m_data[0];
        m_data = &m_data[1];
        return ch;
    }


    u2 ClassReader::readU2() {
        u2 ch = ((u1)m_data[0] << 8) + ((u1)m_data[1]);
        m_data = &m_data[2];
        return ch;
    }

    u4 ClassReader::readU4() {
        unsigned int ch = ((u1)m_data[0]) << 24 | ((u1)m_data[1]) << 16 | ((u1)m_data[2]) << 8 | (u1)m_data[3];
        m_data = &m_data[4];
        return ch;
    }

    u8 ClassReader::readU8() {
        unsigned int ch = (((u1)m_data[0]) << 56) + (((u1)m_data[1]) << 48) + (((u1)m_data[2]) << 40) + (((u1)m_data[3]) << 32) + (((u1)m_data[4]) << 24) + (((u1)m_data[5]) << 16) + (((u1)m_data[6]) << 8) + ((u1)m_data[7]);
        m_data = &m_data[8];
        return ch;
    }

    u1* ClassReader::readU1s(int length) {
        u1* ch = new u1[length];
        memcpy(ch, m_data, length);
        m_data = &m_data[length];
        return ch;
    }

    u1* ClassReader::readU1s(u2 *length) {
        *length = readU2();
        return readU1s((int)*length);
    }

    u2* ClassReader::readU2s(int length) {
        u2 *ch = new u2[length];
        memcpy(ch, m_data, length * 2);
        m_data = &m_data[length * 2];
        return ch;
    }

    u2* ClassReader::readU2s(u2 *length) {
        *length = readU2();
        return readU2s((int)*length);
    }

>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
    string* ClassReader::readString() {
        u2 length = readU2();
        string *s = new string((char*)m_data, 0, length);
        m_data = &m_data[length];
        return s;
    }
}