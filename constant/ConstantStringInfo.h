//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTSTRINGINFO_H
#define JVM_CONSTANTSTRINGINFO_H

#include "../common.h"
#include "../ConstantInfo.h"

class ConstantStringInfo {

private:
    ConstantPool *constantPool;
    u2 stringIndex;
public:

    ConstantStringInfo(ConstantPool* cp):constantPool(cp){}

    virtual ConstantInfo* readInfo(ClassReader* classReader);

    string toString();
};


#endif //JVM_CONSTANTSTRINGINFO_H
