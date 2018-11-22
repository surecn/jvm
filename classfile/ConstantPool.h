//
// Created by 郑邦国 on 2018/11/4.
//

#ifndef JVM_CONSTANTPOOL_H
#define JVM_CONSTANTPOOL_H

#include "../common.h"
#include "ClassReader.h"
#include "ConstantInfo.h"

namespace cls {

    class ConstantPool {
    private:
        ConstantInfo **constantInfos;

        u2 constantPoolSize;

    public:

        ConstantPool(ClassReader *classReader);

        string* getClassName(u2 index);

        string* getUtf8(u2 index);

        ConstantInfo* getConstantInfo(u2 index);

    };


}

#endif //JVM_CONSTANTPOOL_H
