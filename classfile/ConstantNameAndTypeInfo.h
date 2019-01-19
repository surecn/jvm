//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTNAMEANDTYPEINFO_H
#define JVM_CONSTANTNAMEANDTYPEINFO_H


#include "../classfile/ConstantInfo.h"
#include "ConstantPool.h"

namespace cls {
    class ConstantNameAndTypeInfo : public ConstantInfo{

    private:
        u2 nameIndex;
        u2 desciptorIndex;
        ConstantPool *constantPool;
    public:
        ConstantNameAndTypeInfo(ClassReader* classReader, ConstantPool *cp) : constantPool(cp) {
            nameIndex = classReader->readU2();
            desciptorIndex = classReader->readU2();
        }

        string toString() {
            return "NameAndType:" + std::to_string(nameIndex);
        }
    };
}


#endif //JVM_CONSTANTNAMEANDTYPEINFO_H
