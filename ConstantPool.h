//
// Created by 郑邦国 on 2018/11/4.
//

#ifndef JVM_CONSTANTPOOL_H
#define JVM_CONSTANTPOOL_H

#include "common.h"
#include "ClassFile.h"
#import "ConstantInfo.h"

class ConstantPool {
private:
    ConstantInfo* constantInfo;

public:
    string* getClassName(ClassFile* classFile);


    string* getUtf8(u2 index);

    void readConstantPool(ClassReader* classReader);
};


#endif //JVM_CONSTANTPOOL_H
