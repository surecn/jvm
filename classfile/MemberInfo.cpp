#include "MemberInfo.h"//
// Created by 郑邦国 on 2018/11/4.
//

namespace cf {


    MemberInfo::~MemberInfo() {
        delete [] m_attributeInfos;
    }

    u2 MemberInfo::getNameIndex() {
        return m_nameIndex;
    };

    MemberInfo::MemberInfo(ConstantPool *cp, ClassReader *classReader):m_constantPool(cp) {
        m_accessFlags = classReader->readU2();
        m_nameIndex = classReader->readU2();
        //cout << "MemberInfo:" << *(cp->getUtf8(m_nameIndex)) << endl;
        m_descriptorIndex = classReader->readU2();
        m_attributeInfos = AttributeInfo::readAttributes(classReader, m_constantPool, &m_attributeCount);
    }

    MemberInfo** MemberInfo::readMembers(ClassReader *reader, ConstantPool *constantPool, u2 *count) {
        *count = reader->readU2();
        MemberInfo** fields = new MemberInfo*[*count];
        for (int i = 0; i < *count; i++) {
            fields[i] = new MemberInfo(constantPool, reader);
        }
        return fields;
    }

    u2 MemberInfo::getDescriptorIndex() {
        return m_descriptorIndex;
    };

    CodeAttribute* MemberInfo::getCodeAttribute() {
        for (int i = 0, len = m_attributeCount; i < len; ++i) {
            if (m_attributeInfos[i]->getAttributeType() == "Code") {
                return (CodeAttribute*)(m_attributeInfos[i]);
            }
        }
        return NULL;
    }

    u2 MemberInfo::getAccessFlags() {
        return m_accessFlags;
    }

    string* MemberInfo::getName() {
        return m_constantPool->getUtf8(this->m_nameIndex);
    }

    string* MemberInfo::getDescriptor() {
        return m_constantPool->getUtf8(this->m_descriptorIndex);
    }

    ConstantValueAttribute* MemberInfo::getConstantValueAttribute() {
        for (int i = 0, len = m_attributeCount; i < len; ++i) {
            if ("ConstantValue" == m_attributeInfos[i]->getAttributeType()) {
                return (ConstantValueAttribute*)m_attributeInfos[i];
            }
        }
        return NULL;
    }

}