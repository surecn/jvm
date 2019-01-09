//
// Created by 郑邦国 on 2018/12/21.
//

#ifndef JVM_INTERFACEMETHODREF_H
#define JVM_INTERFACEMETHODREF_H


#include "MemberRef.h"

namespace rt {

    class InterfaceMethodRef : public MemberRef {
    private:
        Method *m_method;
    public:
        InterfaceMethodRef(ConstantPool *cp, cf::ConstantInterfaceMethodRefInfo *refInfo);
    };

}


#endif //JVM_INTERFACEMETHODREF_H
