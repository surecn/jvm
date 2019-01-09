//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_SOURCEFILEATTRIBUTE_H
#define JVM_SOURCEFILEATTRIBUTE_H


#include "AttributeInfo.h"

namespace cf {
    class SourceFileAttribute : public AttributeInfo {
    private:
        ConstantPool *m_constantPool;
        string *m_sourceFile;
    public:
        SourceFileAttribute(ConstantPool *cp);

        void readInfo(ClassReader *reader);
    };
}


#endif //JVM_SOURCEFILEATTRIBUTE_H
