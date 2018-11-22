//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_EXCEPTIONATTRIBUTE_H
#define JVM_EXCEPTIONATTRIBUTE_H

#include "../common.h"
#include "AttributeInfo.h"

namespace cls {
    class ExceptionAttribute : public AttributeInfo {
    private:
        u2 numberOfException;
        u2 *exceptionIndexTable;
    public:
        void readInfo(cls::ClassReader *classReader);
    };
}


#endif //JVM_EXCEPTIONATTRIBUTE_H
