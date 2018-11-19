//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTFLOATINFO_H
#define JVM_CONSTANTFLOATINFO_H


#include "ConstantInfo.h"

namespace cls {

    class ConstantFloatInfo : public ConstantInfo {

    private:
        float value;
    public:
        ConstantInfo *readInfo(ClassReader *classReader);
    };

}

#endif //JVM_CONSTANTFLOATINFO_H
