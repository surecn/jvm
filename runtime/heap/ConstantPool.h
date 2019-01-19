//
// Created by 郑邦国 on 2018/12/20.
//

#ifndef JVM_HEAP_CONSTANTPOOL_H
#define JVM_HEAP_CONSTANTPOOL_H


#include "Class.h"
#include "../../classfile/ConstantPool.h"
#include "Constant.h"

namespace rt {

    class ConstantPool {
    private:
        Class *m_class;
        Constant **m_consts;
        int m_size;
    public:
        ConstantPool(Class *cls, cf::ConstantPool *cfCp);
        Class *getClass();

        Constant* getConstant(u4 index);
        ClassRef* getClassRef(u4 index);
        MethodRef* getMethodRef(u4 index);
        FieldRef* getFieldRef(u4 index);
        InterfaceMethodRef* getInterfaceMethodRef(u4 index);
        java_int getInteger(u4 index);
        java_float getFloat(u4 index);
        java_long getLong(u4 index);
        java_double getDouble(u4 index);
        string* getString(u4 index);
    };
}


#endif //JVM_HEAP_CONSTANTPOOL_H
