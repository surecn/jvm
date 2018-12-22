//
// Created by 郑邦国 on 2018/12/20.
//

#ifndef JVM_HEAP_CONSTANTPOOL_H
#define JVM_HEAP_CONSTANTPOOL_H


#include "Class.h"
#include "../../classfile/ConstantPool.h"

namespace rt {

    typedef void* Constant;

    class ConstantPool {
    private:
        Class *m_cls;
        Constant *m_consts;
    public:
        ConstantPool(Class *cls, cf::ConstantPool *cfCp);
        Constant getConstant(u4 index);
    };
}


#endif //JVM_HEAP_CONSTANTPOOL_H
