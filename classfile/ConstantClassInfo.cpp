//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantClassInfo.h"

namespace cf {


    ConstantClassInfo::ConstantClassInfo(ConstantPool *cp) : m_cp(cp){
    }

    string* ConstantClassInfo::getName() {
        return m_cp->getUtf8(m_nameIndex);
    }

    void ConstantClassInfo::print() {
        //cout << "Class:" + std::to_string(m_nameIndex) << endl;
    }

    void* ConstantClassInfo::getValue() {
        return NULL;
    }

    void ConstantClassInfo::readInfo(cf::ClassReader *classReader) {
        m_nameIndex = classReader->readU2();
    }



}