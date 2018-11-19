//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTFIELDREFINFO_H
#define JVM_CONSTANTFIELDREFINFO_H


#include "ConstantInfo.h"

namespace cls {
    class ConstantFieldRefInfo : public ConstantInfo{
    private:
        u2 classIndex;
        u2 nameAndTypeIndex;
    public:
        ConstantInfo* readInfo(ClassReader* classReader);

    };
}


#endif //JVM_CONSTANTFIELDREFINFO_H
