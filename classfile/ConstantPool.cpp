//
// Created by 郑邦国 on 2018/11/4.
//

#include "ConstantPool.h"
#include "Constants.h"

namespace cf {
    ConstantInfo* ConstantPool::getConstantInfo(u2 index) {
        return m_listConstant[index];
    }

    string *ConstantPool::getClassName(u2 index) {
        ConstantClassInfo *classConstantInfo = (ConstantClassInfo*)m_listConstant[index];
        return classConstantInfo->getName();
    }


    string *ConstantPool::getUtf8(u2 index) {
        return ((ConstantUtf8Info*)getConstantInfo(index))->value();
    }

    ConstantPool::ConstantPool(ClassReader *classReader) {
        m_constantPoolSize = classReader->readU2();
        m_listConstant = (ConstantInfo**)(malloc(sizeof(ConstantInfo*) * m_constantPoolSize));
        for (int i = 1; i < m_constantPoolSize; ++i) {
            byte tag = classReader->readU1();
            ConstantInfo* con = ConstantFactory::newConstantInfo(tag, this, classReader);
            m_listConstant[i] = con;
            con->print();
            if (tag == CONSTANT_Double || tag == CONSTANT_Long) {
                i++;
            }
        }
    }

    u2 ConstantPool::getConstantSize() {
        return m_constantPoolSize;
    }

    NameAndType ConstantPool::getNameAndType(u2 index) {
        ConstantNameAndTypeInfo *info = (ConstantNameAndTypeInfo*)getConstantInfo(index);
        NameAndType nameAndType;
        nameAndType.name = getUtf8(info->getNameIndex());
        nameAndType.type = getUtf8(info->getDescriptorIndex());
        return nameAndType;
    }
}


