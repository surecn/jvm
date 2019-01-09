//
// Created by 郑邦国 on 2018/11/4.
//

#include "ConstantPool.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "ConstantFactory.h"

using namespace cls;

ConstantInfo* ConstantPool::getConstantInfo(u2 index) {
    return constantInfos[index];
}

string* ConstantPool::getClassName(u2 index) {
    ConstantClassInfo *classConstantInfo = (ConstantClassInfo*)constantInfos[index];
    return this->getUtf8(classConstantInfo->nameIndex);
}


string* ConstantPool::getUtf8(u2 index) {
    return &getConstantInfo(index)->str;
}

ConstantPool::ConstantPool(ClassReader *classReader) {
    constantPoolSize = classReader->readU2();
    constantInfos = static_cast<ConstantInfo **>(malloc(sizeof(ConstantInfo*) * constantPoolSize));
    for (int i = 0; i < constantPoolSize; ++i) {
        byte tag = classReader->readU1();
        ConstantInfo* con = ConstantFactory::newConstantInfo(tag, this, classReader);
        constantInfos[i] = con;
        if (tag == CONSTANT_Double || tag == CONSTANT_Long) {
            i++;
        }
    }

    for (int j = 0; j < constantPoolSize; ++j) {
        cout << constantInfos[j]->toString() << endl;
=======
=======
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
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
            m_listConstant[i] = ConstantFactory::readConstantInfo(classReader, this);
            //cout << "index:" << i << endl;
            //m_listConstant[i]->print();
            if ( m_listConstant[i]->m_type == CONSTANT_Double ||  m_listConstant[i]->m_type  == CONSTANT_Long) {
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

    void ConstantPool::print() {
        for (int i = 1; i < m_constantPoolSize; ++i) {
            ConstantInfo *constantInfo = m_listConstant[i];
            cout << "index:" << i << "    ";
            constantInfo->print();
        }
<<<<<<< HEAD
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
=======
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
    }
}


