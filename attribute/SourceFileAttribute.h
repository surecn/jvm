//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_SOURCEFILEATTRIBUTE_H
#define JVM_SOURCEFILEATTRIBUTE_H


#include "AttributeInfo.h"

namespace cls {
    class SourceFileAttribute : public AttributeInfo {
    private:
        ConstantPool *constantPool;
        string *sourceFile;
    public:
        SourceFileAttribute(ConstantPool *cp);

        void readInfo(ClassReader *reader);
    };
}


#endif //JVM_SOURCEFILEATTRIBUTE_H
