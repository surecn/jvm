//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_INTERPERTER_H
#define JVM_INTERPERTER_H

#include "classfile/Constants.h"
#include "runtime/heap/Method.h"

class Interperter {
public:
    static void interpret(rt::Method *method);
};


#endif //JVM_INTERPERTER_H
