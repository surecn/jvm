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
        ConstantFloatInfo(ClassReader *classReader) {
            value = classReader->readU4();
        }

        string toString() {
            return "float:" + std::to_string(value);
        }
    };

}

#endif //JVM_CONSTANTFLOATINFO_H
