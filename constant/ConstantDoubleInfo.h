//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTDOUBLEINFO_H
#define JVM_CONSTANTDOUBLEINFO_H


#include "../ConstantInfo.h"

class ConstantDoubleInfo : public ConstantInfo {
private:
    double value;
public:
    virtual ConstantInfo* readInfo(ClassReader* );
};


#endif //JVM_CONSTANTDOUBLEINFO_H
