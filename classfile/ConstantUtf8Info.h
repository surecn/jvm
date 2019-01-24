//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTUTF8INFO_H
#define JVM_CONSTANTUTF8INFO_H


#include "../classfile/ConstantInfo.h"

namespace cf {

    class ConstantUtf8Info : public ConstantInfo {
    private:
        u2 m_length;
        u1 *m_bytes;
        string m_str;
        ConstantPool *m_cp;
        void decodeMUTF8(u1 *bytearr, int utflen);
    public:
        string *value();
        void print();
        void* getValue();
        void readInfo(ClassReader* classReader);
    };

}

#endif //JVM_CONSTANTUTF8INFO_H
