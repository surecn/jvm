//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTMEMBERINFO_H
#define JVM_CONSTANTMEMBERINFO_H


#include "../classfile/ConstantInfo.h"
#include "ConstantPool.h"

namespace cls {
    class ConstantMemberInfo : public ConstantInfo {
    private:
        u2 classIndex;
        u2 nameAndTypeIndex;
        ConstantPool *constantPool;
    public:
        ConstantMemberInfo(ClassReader* classReader, ConstantPool *cp) : constantPool(cp) {
            classIndex = classReader->readU2();
            nameAndTypeIndex = classReader->readU2();

        }

        string toString() {
            return "Member:" + std::to_string(nameAndTypeIndex);
        }
    };
}


#endif //JVM_CONSTANTMEMBERINFO_H
