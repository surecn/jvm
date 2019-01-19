//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTSTRINGINFO_H
#define JVM_CONSTANTSTRINGINFO_H

#include "../common.h"
#include "../classfile/ConstantInfo.h"
#include "ConstantPool.h"

namespace cls {
    class ConstantStringInfo : public ConstantInfo {

    private:

        u2 stringIndex;

        ConstantPool *constantPool;

    public:

        ConstantStringInfo(ClassReader* classReader, ConstantPool *cp) : constantPool(cp) {
            stringIndex = classReader->readU2();
        }

        string toString() {
            return "string:" + stringIndex;
        }
    };
}


#endif //JVM_CONSTANTSTRINGINFO_H
