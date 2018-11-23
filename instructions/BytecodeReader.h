//
// Created by 郑邦国 on 2018/11/23.
//

#ifndef JVM_BYTECODEREADER_H
#define JVM_BYTECODEREADER_H


#include "../common.h"

namespace rt {
    class BytecodeReader {
    private:
        u1 *code;
        int pc;
    public:
        void reset(u1 *_code, int _pc);

        u1 readU1();

        u2 readU2();

        u4 readU4();
    };
}


#endif //JVM_BYTECODEREADER_H
