//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTMEMBERINFO_H
#define JVM_CONSTANTMEMBERINFO_H


#include "../classfile/ConstantInfo.h"
#include "ConstantPool.h"

namespace cf {

    class ConstantMemberInfo : public ConstantInfo {
    private:
        u2 m_classIndex;
        u2 m_nameAndTypeIndex;
        ConstantPool *m_cp;
    public:
        ConstantMemberInfo(ConstantPool *cp);
        void print();
        void* getValue();
        string *getClassName();
        NameAndType getNameAndType();
        void readInfo(ClassReader* classReader);
    };



    class ConstantFieldRefInfo : public ConstantMemberInfo {
    private:
    public:
        ConstantFieldRefInfo(ConstantPool *cp);
    };

    class ConstantMethodRefInfo : public ConstantMemberInfo {
    private:
    public:
        ConstantMethodRefInfo(ConstantPool *cp);
    };

    class ConstantInterfaceMethodRefInfo : public ConstantMemberInfo {
    private:
    public:
        ConstantInterfaceMethodRefInfo(ConstantPool *cp);
    };


}


#endif //JVM_CONSTANTMEMBERINFO_H
