#include "MemberInfo.h"//
// Created by 郑邦国 on 2018/11/4.
//

#include "MemberInfo.h"

using namespace cls;

MemberInfo** MemberInfo::readMembers(ConstantPool *constantPool, ClassReader *reader) {
    u2 fieldCount = reader->readU2();
    MemberInfo** fields = new MemberInfo*[fieldCount];

    for (int i = 0; i < fieldCount; i++) {
        fields[i] = new MemberInfo(constantPool, reader);
    }

    return fields;
}

MemberInfo::MemberInfo(ConstantPool *cp, ClassReader *classReader):constantPool() {
    accessFlags = classReader->readU2();
    nameIndex = classReader->readU2();
    descriptorIndex =classReader->readU2();
    attributeInfos = AttributeInfo::readAttributes(classReader, constantPool);
}