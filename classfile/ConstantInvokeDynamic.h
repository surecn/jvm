//
// Created by 郑邦国 on 2018/12/25.
//

#ifndef JVM_CONSTANTINVOKEDYNAMIC_H
#define JVM_CONSTANTINVOKEDYNAMIC_H


#include "ConstantInfo.h"

namespace cf {

    class ConstantMethodHandleInfo : public ConstantInfo {
    private:
        u1 m_referenceKind;
        u2 m_referenceIndex;
    public:
        void readInfo(ClassReader* classReader);
    };

    class ConstantMethodTypeInfo : public ConstantInfo {
    private:
        u2 m_descriptorIndex;
    public:
        void readInfo(ClassReader* classReader);
    };

    class ConstantInvokeDynamicInfo: public ConstantInfo {
    private:
        u2 m_bootstrapMethodAttrIndex;
        u2 m_nameAndTypeIndex;
    public:
        void readInfo(ClassReader* classReader);
    };
}


#endif //JVM_CONSTANTINVOKEDYNAMIC_H
