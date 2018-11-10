//
// Created by 郑邦国 on 2018/11/5.
//

#include "ConstantInfo.h"
#include "constant/ConstantIntegerInfo.h"
#include "constant/ConstantLongInfo.h"

ConstantInfo* ConstantInfo::readConstantInfo(ClassReader *classReader, ConstantPool* constantPool) {
    u2 tag = classReader->readU2();
    newConstantInfo(tag, constantPool);
}

ConstantInfo* ConstantInfo::newConstantInfo(u2 tag, ConstantPool *constantPool) {
    switch (tag) {
        case CONSTANT_Integer:
            return new ConstantIntegerInfo();
        case CONSTANT_Long:
            return new ConstantLongInfo();
        case CONSTANT_FLoat:
            return
    }
}