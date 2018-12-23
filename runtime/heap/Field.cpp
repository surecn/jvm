//
// Created by 郑邦国 on 2018/12/19.
//

#include "Field.h"
#include "AccessFlags.h"
#include "../../classfile/attribute/ConstantValueAttribute.h"

namespace rt {

    Field** Field::newFields(rt::Class *cls, cf::MemberInfo **cfFields, int count) {
        Field **fields = new Field*[count];
        for (int i = 0; i < count; ++i) {
            cf::MemberInfo *memberInfo = cfFields[i];
            fields[i] = new Field();
            fields[i]->setClass(cls);
            fields[i]->copyMemberInfo(cfFields[i]);
            fields[i]->copyAttributes(cfFields[i]);
        }
        return fields;
    }

    bool Field::isVolatile() {
        return 0 != m_accessFlags & ACC_VOLATILE;
    }

    bool Field::isTransient() {
        return 0 != m_accessFlags & ACC_TRANSIENT;
    }

    bool Field::isEnum() {
        return 0 != m_accessFlags & ACC_ENUM;
    }

    bool Field::isLongOrDouble() {
        return *m_descriptor == "J" || *m_descriptor == "D";
    }

    u4 Field::getSlotId() const {
        return m_slotId;
    }

    void Field::setSlotId(u4 slotId) {
        Field::m_slotId = slotId;
    }

    void Field::copyAttributes(cf::MemberInfo *memberInfo) {
        cf::ConstantValueAttribute *attribute = memberInfo->getConstantValueAttribute();
        if (attribute != NULL) {
            m_constValueIndex = attribute->getConstantValueIndex();
        }
    }

    u4 Field::getConstValueIndex() const {
        return m_constValueIndex;
    }
}