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
        m_listConstant = new ConstantInfo*[m_constantPoolSize];
        for (int i = 1; i < m_constantPoolSize; ++i) {
            //cout << "index:" << i << endl;
            m_listConstant[i] = ConstantFactory::readConstantInfo(classReader, this);
            //m_listConstant[i]->print();
            if ( m_listConstant[i]->m_type == CONSTANT_Double ||  m_listConstant[i]->m_type  == CONSTANT_Long) {
                i++;
            }
        }
    }

    ConstantPool::~ConstantPool() {
        delete  [] m_listConstant;
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

    void ConstantPool::print() {
        for (int i = 1; i < m_constantPoolSize; ++i) {
            ConstantInfo *constantInfo = m_listConstant[i];
            cout << "index:" << i << "    ";
            constantInfo->print();
        }
    }
}


