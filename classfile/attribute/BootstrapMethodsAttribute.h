//
// Created by 郑邦国 on 2018/12/25.
//

#ifndef JVM_BOOTSTRAPMETHODSATTRIBUTE_H
#define JVM_BOOTSTRAPMETHODSATTRIBUTE_H


#include "AttributeInfo.h"

namespace cf {

    struct BootstrapMethod  {
        u2 bootstrapMethodRef;
        u2 *bootstrapArguments;
        u2 bootstrapArgumentSize;
    };

    class BootstrapMethodsAttribute : public AttributeInfo{
    private:
        BootstrapMethod **m_bootstrapMethod;
    public:
        void readInfo(ClassReader* classReader);
    };

}


#endif //JVM_BOOTSTRAPMETHODSATTRIBUTE_H
