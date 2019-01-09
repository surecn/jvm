//
// Created by 郑邦国 on 2018/12/25.
//

#ifndef JVM_SIGNATUREATTRIBUTE_H
#define JVM_SIGNATUREATTRIBUTE_H


#include "AttributeInfo.h"

namespace cf {

    class SignatureAttribute : public AttributeInfo {
    private:
        ConstantPool *m_cp;
        u2 m_signatureIndex;
    public:
        void readInfo(ClassReader* classReader);
        string *getSignature();
    };

}


#endif //JVM_SIGNATUREATTRIBUTE_H
