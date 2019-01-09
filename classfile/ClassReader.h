//
// Created by 郑邦国 on 2018/11/2.
//

#ifndef JVM_CLASSREADER_H
#define JVM_CLASSREADER_H


#include "../common.h"

namespace cf {
    class ClassReader {
    private:
        //class文件
        byte *m_data;
    public:
        ClassReader(byte* &_data);
        u1 readU1(); //u1
        u2 readU2(); // u2
        u4 readU4(); //u4
        u8 readU8(); //u8
<<<<<<< HEAD
        u2* readU2s(); //u2[]
        u1* readU1s(); //u8[]
        u1* readU1s(int length);
=======
        u2* readU2s(u2 *length);
        u2* readU2s(int length); //u2[]
        u1* readU1s(u2 *length); //u8[]
        u1* readU1s(int length);
        string* readString();
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
    };

}



#endif //JVM_CLASSREADER_H
