//
// Created by 郑邦国 on 2018/12/21.
//

#include "FieldRef.h"

namespace rt {

    FieldRef::FieldRef(rt::ConstantPool *cp, cf::ConstantFieldRefInfo *refInfo) {
        m_field = NULL;
        setConstantPool(cp);
        copyMemberRefInfo(refInfo);
    }

    void FieldRef::resolveFieldRef() {
        Class *cls_d = m_cp->getClass();
        Class *cls_c = resolvedClass();
        Field *field = lookupField(cls_c, m_name, m_descriptor);
        if (field == NULL) {
            cout << "java.lang.NoSuchFieldError" << endl;
        }
        if (!field->isAccessiableTo(cls_d)) {
            cout << "java.lang.IllegalAccessError" << endl;
        }
        m_field = field;
    }

    Field* FieldRef::resolvedField() {
        if (m_field == NULL) {
            resolveFieldRef();
        }
        return m_field;
    }

    Field* FieldRef::lookupField(rt::Class *cls, string *name, string *descriptor) {
        Field **fields = cls->getFields();
        u4 fieldCount = cls->getFieldCount();
        for (int i = 0; i < fieldCount; ++i) {
            if (*fields[i]->getName() == *name && *fields[i]->getDescriptor() == *descriptor) {
                return fields[i];
            }
        }
        Class** interfaces = cls->getInterfaces();
        u4 interfaceCount = cls->getInterfaceCount();
        for (int j = 0; j < interfaceCount; ++j) {
            Field *field = lookupField(interfaces[j], name, descriptor);
            if (field != NULL) {
                return field;
            }
        }
        if (cls->getSuperClass() != NULL) {
            lookupField(cls->getSuperClass(), name, descriptor);
        }
        return NULL;
    }

}
