//
// Created by 郑邦国 on 2018/12/21.
//

#ifndef JVM_SYMREF_H
#define JVM_SYMREF_H


#include "ConstantPool.h"

namespace rt {

    class SymRef {
    private:
        ConstantPool *m_cp;
        string *m_className;
        Class *m_cls;
    public:
        SymRef(){};
        SymRef(ConstantPool *cp, cf::ConstantClassInfo *classInfo);
        void setClassName(string *className);
        void setConstantPool(ConstantPool *constantPool);
    };

}


#endif //JVM_SYMREF_H
