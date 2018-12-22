//
// Created by 郑邦国 on 2018/12/19.
//

#ifndef JVM_CLASSMEMBER_H
#define JVM_CLASSMEMBER_H


#include "../../common.h"
#include "../../classfile/Constants.h"

namespace rt{
    extern class Class;
    class ClassMember {
    private:
        u2 m_accessFlags;
        string *m_name;
        string *m_descriptor;
    public:
        Class *_cls;
        ClassMember* copyMemberInfo(cf::MemberInfo *memberInfo);
    };
}


#endif //JVM_CLASSMEMBER_H
