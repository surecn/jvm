//
// Created by 郑邦国 on 2018/11/21.
//

#ifndef JVM_CONSTANTVALUEATTRIBUTE_H
#define JVM_CONSTANTVALUEATTRIBUTE_H


#include "AttributeInfo.h"

namespace cf {
    class ConstantValueAttribute : public AttributeInfo {
    private:
        u2 m_constantValueIndex;
    public:
        void readInfo(ClassReader* classReader);
        u2 getConstantValueIndex() const;
    };
}


#endif //JVM_CONSTANTVALUEATTRIBUTE_H
