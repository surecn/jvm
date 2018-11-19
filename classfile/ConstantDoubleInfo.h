//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTDOUBLEINFO_H
#define JVM_CONSTANTDOUBLEINFO_H


#include "ConstantInfo.h"

namespace cls {
    class ConstantDoubleInfo : public ConstantInfo {
    private:
        double value;
    public:
        ConstantInfo* readInfo(ClassReader* classReader);
    };
}


#endif //JVM_CONSTANTDOUBLEINFO_H
