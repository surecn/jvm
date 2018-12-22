//
// Created by 郑邦国 on 2018/12/21.
//

#ifndef JVM_METHODREF_H
#define JVM_METHODREF_H


#include "MemberRef.h"

namespace rt {

    class MethodRef : public MemberRef {
    private:
        Method *m_method;
    public:
        MethodRef(ConstantPool* cp, cf::ConstantMethodRefInfo *refInfo);
    };




}

#endif //JVM_METHODREF_H
