//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTCLASSINFO_H
#define JVM_CONSTANTCLASSINFO_H


#include "ConstantInfo.h"
#include "ConstantPool.h"

namespace cls {
    class ConstantClassInfo : public ConstantInfo {

    public:
        ConstantPool *constantPool;
        u2 nameIndex;

    public:
        ConstantClassInfo(ClassReader* classReader, ConstantPool* cp):constantPool(cp){
            nameIndex = classReader->readU2();
        }
        string* getName();

        string toString() {
            return "Class:" + std::to_string(nameIndex);
        }
    };
}


#endif //JVM_CONSTANTCLASSINFO_H
