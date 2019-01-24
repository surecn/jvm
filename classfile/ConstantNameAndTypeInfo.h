//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTNAMEANDTYPEINFO_H
#define JVM_CONSTANTNAMEANDTYPEINFO_H


#include "../classfile/ConstantInfo.h"
#include "ConstantPool.h"

namespace cf {

    class ConstantNameAndTypeInfo : public ConstantInfo{
    private:
        u2 m_name_index;
        u2 m_desciptor_index;
        ConstantPool *m_cp;
    public:
        ConstantNameAndTypeInfo(ConstantPool *cp);
        void print();
        void* getValue();
        u2 getNameIndex();
        u2 getDescriptorIndex();
        void readInfo(ClassReader* classReader);
    };
}


#endif //JVM_CONSTANTNAMEANDTYPEINFO_H
