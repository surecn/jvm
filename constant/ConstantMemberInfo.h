//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTMEMBERINFO_H
#define JVM_CONSTANTMEMBERINFO_H


#include "../ConstantInfo.h"

class ConstantMemberInfo : public ConstantInfo {
private:
    u2 classIndex;
    u2 nameAndTypeIndex;
public:
    virtual ConstantInfo* readInfo(ClassReader* classReader);
};


#endif //JVM_CONSTANTMEMBERINFO_H
