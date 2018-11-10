//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTCLASSINFO_H
#define JVM_CONSTANTCLASSINFO_H


#include "../ConstantInfo.h"

class ConstantClassInfo : public ConstantInfo {

private:
    ConstantPool constantPool;
    u2 nameIndex;

public:
    ConstantClassInfo(ConstantPool* cp):constantPool(cp){}

    virtual ConstantInfo* readInfo(ClassReader* classReader);

    string* getName();
};


#endif //JVM_CONSTANTCLASSINFO_H
