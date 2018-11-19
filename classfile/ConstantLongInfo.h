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
        inline long getLong() {
            return value;
        }

        ConstantInfo* readInfo(ClassReader* classReader);
    };
}

#endif //JVM_CONSTANTLONGINFO_H
