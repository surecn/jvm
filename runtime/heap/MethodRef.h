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
        void resolvedMethodRef();
        Method* lookupMethod(Class *cls, string *name, string *descriptor);

    public:
        MethodRef(ConstantPool* cp, cf::ConstantMethodRefInfo *refInfo);
        Method* resolvedMethod();

    };




}

#endif //JVM_METHODREF_H
