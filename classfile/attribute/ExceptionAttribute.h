//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_EXCEPTIONATTRIBUTE_H
#define JVM_EXCEPTIONATTRIBUTE_H

#include "../../common.h"
#include "AttributeInfo.h"

namespace cf {
    class ExceptionAttribute : public AttributeInfo {
    private:
        u2 m_numberOfException;
        u2 *m_exceptionIndexTable;
    public:

        ~ExceptionAttribute();
        void readInfo(cf::ClassReader *classReader);
    };
}


#endif //JVM_EXCEPTIONATTRIBUTE_H
