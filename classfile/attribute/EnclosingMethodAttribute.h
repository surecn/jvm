//
// Created by 郑邦国 on 2018/12/25.
//

#ifndef JVM_ENCLOSINGMETHODATTRIBUTE_H
#define JVM_ENCLOSINGMETHODATTRIBUTE_H


#include "AttributeInfo.h"

namespace cf {

    class EnclosingMethodAttribute : public AttributeInfo {
    private:
        ConstantPool *m_cp;
        u2 m_classIndex;
        u2 m_methodIndex;
    public:
        void readInfo(ClassReader* classReader);
        string* getClassName();
        NameAndType getNameAndDescriptor();
    };

}


#endif //JVM_ENCLOSINGMETHODATTRIBUTE_H
