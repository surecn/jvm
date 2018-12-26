//
// Created by 郑邦国 on 2018/12/25.
//

#ifndef JVM_INNERCLASSESATTRIBUTE_H
#define JVM_INNERCLASSESATTRIBUTE_H


#include "AttributeInfo.h"

namespace cf {

    struct InnerClassInfo {
        u2 innerClassInfoIndex;
        u2 outerClassInfoIndex;
        u2 innerNameIndex;
        u2 innerClassAccessFlags;
    };

    class InnerClassesAttribute : public AttributeInfo {
    private:
        InnerClassInfo **m_classes;
        u2 m_classesCount;
    public:
        void readInfo(ClassReader* classReader);
    };

}


#endif //JVM_INNERCLASSESATTRIBUTE_H
