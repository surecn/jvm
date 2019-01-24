//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantNameAndTypeInfo.h"

namespace cf {


    ConstantNameAndTypeInfo::ConstantNameAndTypeInfo(ConstantPool *cp) : m_cp(cp) {
    }

    void ConstantNameAndTypeInfo::readInfo(cf::ClassReader *classReader) {
        m_name_index = classReader->readU2();
        m_desciptor_index = classReader->readU2();
    }

    void ConstantNameAndTypeInfo::print() {
        //cout << "NameAndType:" + std::to_string(m_name_index) << endl;
    }

    void* ConstantNameAndTypeInfo::getValue() {
        return NULL;
    }

    u2 ConstantNameAndTypeInfo::getNameIndex() {
        return m_name_index;
    }

    u2 ConstantNameAndTypeInfo::getDescriptorIndex() {
        return m_desciptor_index;
    }

}