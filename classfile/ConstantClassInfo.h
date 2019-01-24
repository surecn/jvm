//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTCLASSINFO_H
#define JVM_CONSTANTCLASSINFO_H


#include "ConstantInfo.h"
#include "ConstantPool.h"

namespace cf {
    class ConstantClassInfo : public ConstantInfo {
    private:
        ConstantPool *m_cp;
        u2 m_nameIndex;
    public:
        ConstantClassInfo(ConstantPool* cp);
        string* getName();
        void print();
        void* getValue();
        void readInfo(ClassReader* classReader);
    };
}


#endif //JVM_CONSTANTCLASSINFO_H
