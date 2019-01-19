//
// Created by 郑邦国 on 2019/1/3.
//

#ifndef JVM_ARRAYCLASS_H
#define JVM_ARRAYCLASS_H


#include "Class.h"

namespace rt {

    class ArrayClass : public Class {
    private:
        string getComponentClassName(string className);
        string toClassName(string descriptor);
    public:
        Object *newArrayObject(java_int count);
        Class *getComponentClass();
    };

}


#endif //JVM_ARRAYCLASS_H
