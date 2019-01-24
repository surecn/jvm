//
// Created by 郑邦国 on 2018/11/5.
//

#ifndef JVM_CONSTANTINFO_H
#define JVM_CONSTANTINFO_H

#include "../common.h"
#include "ClassReader.h"


namespace cf {

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

    extern class ConstantPool;

    class ConstantInfo {
    public:
        int m_type;
    public:
        virtual void print();
        virtual void* getValue();
        virtual void readInfo(ClassReader* classReader) = 0;
        void setType(int type);
    };

    class ConstantFactory {
    public:
        static ConstantInfo *readConstantInfo(ClassReader *classReader, ConstantPool *constantPool);
        static ConstantInfo *newConstantInfo(u1 tag, ConstantPool *constantPool);
    };

}

#endif //JVM_CONSTANTINFO_H
