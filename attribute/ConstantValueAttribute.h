//
// Created by 郑邦国 on 2018/11/21.
//

#ifndef JVM_CONSTANTVALUEATTRIBUTE_H
#define JVM_CONSTANTVALUEATTRIBUTE_H


#include "AttributeInfo.h"

namespace cls {
    class ConstantValueAttribute : public AttributeInfo {
    private:
        u2 constantValueIndex;
    public:
        void readInfo(ClassReader* classReader);
    };
}


#endif //JVM_CONSTANTVALUEATTRIBUTE_H
