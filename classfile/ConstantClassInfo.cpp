//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantClassInfo.h"

using namespace cls;


string* ConstantClassInfo::getName() {
    constantPool->getClassName(nameIndex);
}