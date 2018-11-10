//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTLONGINFO_H
#define JVM_CONSTANTLONGINFO_H


#include "../ConstantInfo.h"

class ConstantLongInfo : public ConstantInfo {

private:
    long value;
public:
    long getLong() {
        return value;
    }

    virtual ConstantInfo* readInfo(ClassReader* classReader);
};


#endif //JVM_CONSTANTLONGINFO_H
