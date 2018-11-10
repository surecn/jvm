//
// Created by 郑邦国 on 2018/11/5.
//

#ifndef JVM_CONSTANTINFO_H
#define JVM_CONSTANTINFO_H

#include "common.h"
#include "ClassReader.h"

const int CONSTANT_Class = 7;

const int CONSTANT_Fieldref = 9;

const int CONSTANT_Methodref = 10;

const int CONSTANT_InterfaceMethodRef = 11;

const int CONSTANT_String = 8;

const int CONSTANT_Integer = 3;

const int CONSTANT_FLoat = 4;

const int CONSTANT_Long = 5;

const int CONSTANT_Double = 6;

const int CONSTANT_NameAndType = 12;

const int CONSTANT_Utf8 = 1;

const int CONSTANT_MethodHandle = 15;

const int CONSTANT_MethodType = 16;

const int CONSTANT_InvokeDynamic = 18;



class ConstantInfo {

public:
    int type;

    void readInfo(ClassReader* classReader);

    ConstantInfo* readConstantInfo(ClassReader* classReader);

    ConstantInfo* newConstantInfo(ClassReader* classReader);
};


#endif //JVM_CONSTANTINFO_H
