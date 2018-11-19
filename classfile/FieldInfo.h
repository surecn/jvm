//
// Created by 郑邦国 on 2018/11/4.
//

#ifndef JVM_FIELDINFO_H
#define JVM_FIELDINFO_H

#include "../common.h"
#include "../attribute/AttributeInfo.h"

namespace cls {

    class FieldInfo {
    private:
        u2  accessFlags;
        u2  nameIndex;
        u2  descriptorIndex;
        u2  attributeCount;
        AttributeInfo* attributeInfos;
    };

}

#endif //JVM_FIELDINFO_H
