//
// Created by 郑邦国 on 2018/12/21.
//

#ifndef JVM_MEMBERREF_H
#define JVM_MEMBERREF_H


#include "SymRef.h"

namespace rt {

    class MemberRef : public SymRef {
    private:
        string *m_name;
        string *m_descriptor;
    public:
        void copyMemberRefInfo(cf::ConstantMemberInfo *memberInfo);
    };
}


#endif //JVM_MEMBERREF_H
