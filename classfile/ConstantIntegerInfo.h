//
// Created by 郑邦国 on 2018/11/10.
//

#ifndef JVM_CONSTANTINTEGERINFO_H
#define JVM_CONSTANTINTEGERINFO_H


#include "../common.h"
#include "ClassReader.h"
#include "ConstantInfo.h"

using namespace cls;

class ConstantIntegerInfo : public ConstantInfo {
public:
    int value;
    ConstantIntegerInfo(ClassReader *classReader) {
        value = classReader->readU4();
    }

    string toString() {
        return "integer:" + std::to_string(value);
    }
};


#endif //JVM_CONSTANTINTEGERINFO_H
