//
// Created by 郑邦国 on 2018/11/23.
//

#ifndef JVM_BYTECODEREADER_H
#define JVM_BYTECODEREADER_H


#include "../../common.h"

namespace rt {
    class BytecodeReader {
    private:
        u1 *code;
        int pc;
    public:
        void reset(u1 *_code, int _pc);
        u1 readU1();
        u2 readU2();
        short readC2();
        u4 readU4();
        u4* readU4s(u4 length);
        u4* readU4s(u4* length);
        void skipPadding();
        int PC();
    };
}


#endif //JVM_BYTECODEREADER_H
