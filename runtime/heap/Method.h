//
// Created by 郑邦国 on 2018/12/19.
//

#ifndef JVM_METHOD_H
#define JVM_METHOD_H


#include "ClassMember.h"

namespace rt {
    class Method : public ClassMember {
    private:
        u4 m_maxStack;
        u4 m_maxLocals;
        u1 *m_code;
        u4 m_argSlotCount;
        void copyAttributes(cf::MemberInfo *memberInfo);
        void calcArgSlotCount(const vector<char> paramTypes);
        Method();
    public:
        static Method** newMethods(Class *cls, cf::MemberInfo **cfMembers, int count);
        u4 getMaxStack() const;
        u4 getMaxLocals() const;
        bool isSynchronized();
        bool isBridge();
        bool isVarargs();
        bool isNative();
        bool isAbstract();
        bool isStrict();
        u1 *getCode();
        u4 getArgSlotCount();
        void injectCodeAttribute(char returnType);
    };
}


#endif //JVM_METHOD_H
