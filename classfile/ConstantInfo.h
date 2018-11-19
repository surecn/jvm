//
// Created by 郑邦国 on 2018/11/5.
//

#ifndef JVM_CONSTANTINFO_H
#define JVM_CONSTANTINFO_H

#include "../common.h"
#include "ClassReader.h"


namespace cls {

    static const int CONSTANT_Class = 7;

    static const int CONSTANT_Fieldref = 9;

    static const int CONSTANT_Methodref = 10;

    static const int CONSTANT_InterfaceMethodRef = 11;

    static const int CONSTANT_String = 8;

    static const int CONSTANT_Integer = 3;

    static const int CONSTANT_FLoat = 4;

    static const int CONSTANT_Long = 5;

    static const int CONSTANT_Double = 6;

    static const int CONSTANT_NameAndType = 12;

    static const int CONSTANT_Utf8 = 1;

    static const int CONSTANT_MethodHandle = 15;

    const int CONSTANT_MethodType = 16;

    const int CONSTANT_InvokeDynamic = 18;

    class ConstantInfo {
    public:
        int type;

        string str;
    public:

         ConstantInfo* readInfo(ClassReader* classReader);

    };


}

#endif //JVM_CONSTANTINFO_H
