//
// Created by 郑邦国 on 2018/12/25.
//

#include "ConstantNumeric.h"

namespace cf {

    void ConstantFloatInfo::readInfo(cf::ClassReader *classReader) {
        m_value = classReader->readU4();
    }

    void ConstantFloatInfo::print() {
        cout << "float:" + std::to_string(m_value) << endl;
    }

    void* ConstantFloatInfo::getValue() {
        return &m_value;
    }

    void ConstantDoubleInfo::readInfo(cf::ClassReader *classReader) {
        m_value = classReader->readU8();
    }


    void ConstantDoubleInfo::print() {
        cout << "double:" + std::to_string(m_value) << endl;
    }

    void* ConstantDoubleInfo::getValue() {
        return &m_value;
    }

    void ConstantIntegerInfo::readInfo(cf::ClassReader *classReader) {
        m_value = classReader->readU4();
    }

    void ConstantIntegerInfo::print() {
        cout << "integer:" + std::to_string(m_value) << endl;
    }

    void* ConstantIntegerInfo::getValue() {
        return &m_value;
    }

    void ConstantLongInfo::readInfo(cf::ClassReader *classReader) {
        m_value = classReader->readU8();
    }

    void ConstantLongInfo::print() {
        cout << "long:" + std::to_string(m_value) << endl;
    }

    void* ConstantLongInfo::getValue() {
        return &m_value;
    }

}