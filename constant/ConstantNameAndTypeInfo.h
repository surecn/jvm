//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTNAMEANDTYPEINFO_H
#define JVM_CONSTANTNAMEANDTYPEINFO_H


#include "../ConstantInfo.h"

class ConstantNameAndTypeInfo : public ConstantInfo{

private:
    u2 nameIndex;
    u2 desciptorIndex;
public:

    virtual ConstantInfo* readInfo(ClassReader* classReader);
};


#endif //JVM_CONSTANTNAMEANDTYPEINFO_H
