//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_UNPARSEDATTRIBUTE_H
#define JVM_UNPARSEDATTRIBUTE_H


#include "../../common.h"
#include "../ClassReader.h"
#include "AttributeInfo.h"

namespace cf {
    class UnparsedAttribute : public AttributeInfo {
    private:
        string m_name;
        int m_length;
        u1 *m_info;

    public:
        UnparsedAttribute(string *n, int len):m_name(m_name), m_length(len) {}

        void readInfo(ClassReader *classReader);
    };

}

#endif //JVM_UNPARSEDATTRIBUTE_H
