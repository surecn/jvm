//
// Created by 郑邦国 on 2018/11/2.
//

#ifndef JVM_CLASSREADER_H
#define JVM_CLASSREADER_H


#include "../common.h"

namespace cls {
    class ClassReader {
    private:
        byte *data;
    public:
        ClassReader(byte* &_data):data(_data) {}

        u1 readU1(); //u1
        u2 readU2(); // u2
        u4 readU4(); //u4
        u8 readU8(); //u8
        u2* readU2s(); //u2[]
        u1* readU1s(); //u8[]
    };

}



#endif //JVM_CLASSREADER_H
