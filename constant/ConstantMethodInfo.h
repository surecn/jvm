//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTMETHODINFO_H
#define JVM_CONSTANTMETHODINFO_H


#include "../ConstantInfo.h"

class ConstantMethodInfo : public ConstantInfo {
private:
    u2 classIndex;
    u2 nameAndTypeIndex;
public:
    virtual ConstantInfo* readInfo(ClassReader* classReader);
};


#endif //JVM_CONSTANTMETHODINFO_H
