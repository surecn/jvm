//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_UNPARSEDATTRIBUTE_H
#define JVM_UNPARSEDATTRIBUTE_H


#include "../common.h"
#include "../classfile/ClassReader.h"

namespace cls {
    class UnparsedAttribute {
    private:
        string name;
        int length;
        u1 *info;

    public:
        UnparsedAttribute(string n, int len):name(name), length(len) {}

        void readInfo(ClassReader *classReader);
    };

}

#endif //JVM_UNPARSEDATTRIBUTE_H
