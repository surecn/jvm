//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTMETHODINFO_H
#define JVM_CONSTANTMETHODINFO_H


#include "../classfile/ConstantInfo.h"

namespace cls {
    class ConstantMethodInfo : public ConstantInfo {
    private:
        u2 classIndex;
        u2 nameAndTypeIndex;
    public:
        ConstantInfo* readInfo(ClassReader* classReader);
    };
}


#endif //JVM_CONSTANTMETHODINFO_H
