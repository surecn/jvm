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
    protected:
        u2 m_accessFlags;
        string *m_name;
        string *m_descriptor;
        Class *m_class;
    public:
        Class *getClass() const;
        void setClass(Class *cls);
        bool isPublic();
        bool isPrivate();
        bool isProtected();
        bool isStatic();
        bool isFinal();
        bool isSynthetic();
        void copyMemberInfo(cf::MemberInfo *memberInfo);
        string *getDescriptor() const;
        string *getName() const;
        bool isAccessiableTo(Class *cls);
    };
}


#endif //JVM_CLASSMEMBER_H
