//
// Created by 郑邦国 on 2018/12/21.
//

#ifndef JVM_MEMBERREF_H
#define JVM_MEMBERREF_H


#include "SymRef.h"
#include "../../classfile/ConstantMemberInfo.h"

namespace rt {

    class MemberRef : public SymRef {
    protected:
        string *m_name;
        string *m_descriptor;
    public:
        void copyMemberRefInfo(cf::ConstantMemberInfo *memberInfo);
        string *getName();
        string *getDescriptor();
    };
}


#endif //JVM_MEMBERREF_H
