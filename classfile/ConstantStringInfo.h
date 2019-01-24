//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTSTRINGINFO_H
#define JVM_CONSTANTSTRINGINFO_H

#include "../common.h"
#include "../classfile/ConstantInfo.h"
#include "ConstantPool.h"

namespace cf {
    class ConstantStringInfo : public ConstantInfo {
    private:
        u2 m_stringIndex;
        ConstantPool *m_cp;
    public:
        ConstantStringInfo(ConstantPool *cp);
        void print();
        void* getValue();
        void readInfo(ClassReader* classReader);
    };
}


#endif //JVM_CONSTANTSTRINGINFO_H
