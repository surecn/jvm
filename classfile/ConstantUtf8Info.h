//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTUTF8INFO_H
#define JVM_CONSTANTUTF8INFO_H


#include "../classfile/ConstantInfo.h"

namespace cls {
    class ConstantUtf8Info : public ConstantInfo {
    private:
        u2 length;
        u1* bytes;
    public:
        ConstantInfo* readInfo(ClassReader* classReader);
    };

}

#endif //JVM_CONSTANTUTF8INFO_H