//
// Created by 郑邦国 on 2019/1/10.
//

#ifndef JVM_HEAP_CONSTANT_H
#define JVM_HEAP_CONSTANT_H


#include "../../common.h"
#include "ClassRef.h"
#include "MethodRef.h"
#include "FieldRef.h"
#include "InterfaceMethodRef.h"

namespace rt {

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
    static const int CONSTANT_MethodType = 16;
    static const int CONSTANT_InvokeDynamic = 18;

    struct Constant {
        int type;
    };

    struct ConstantInteger : public Constant {
        java_int value;
    };

    struct ConstantFloat : public Constant {
        java_float value;
    };

    struct ConstantLong : public Constant {
        java_long value;
    };

    struct ConstantDouble : public Constant {
        java_double value;
    };

    struct ConstantString : public Constant {
        string value;
    };

    struct ConstantClassRef : public Constant {
        rt::ClassRef *ref;
    };

    struct ConstantFieldRef : public Constant {
        rt::FieldRef *ref;
    };

    struct ConstantMethodRef : public Constant {
        rt::MethodRef *ref;
    };

    struct ConstantIngerfaceMethodRef : public Constant {
        rt::InterfaceMethodRef *ref;
    };

}


#endif //JVM_HEAP_CONSTANT_H
