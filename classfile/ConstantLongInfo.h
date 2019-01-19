//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTLONGINFO_H
#define JVM_CONSTANTLONGINFO_H


#include "ConstantInfo.h"

namespace cls {
    class ConstantLongInfo : public ConstantInfo {

    private:
        long value;
    public:

        ConstantLongInfo(ClassReader * classReader) {
            value = classReader->readU8();
        }

        string toString() {
            return "long:" + std::to_string(value);
        }
    };
}

#endif //JVM_CONSTANTLONGINFO_H
