//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTINTEGERINFO_H
#define JVM_CONSTANTINTEGERINFO_H


#include "../common.h"
#include "../ConstantInfo.h"

class ConstantIntegerInfo:public ConstantInfo {
public:
    u1 tag;
    int value;

    virtual ConstantInfo* readInfo(ClassReader *classReader);
};


#endif //JVM_CONSTANTINTEGERINFO_H
