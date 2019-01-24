//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantMemberInfo.h"

namespace cf {

    ConstantMemberInfo::ConstantMemberInfo(ConstantPool *cp) : m_cp(cp) {
    }

    void ConstantMemberInfo::print() {
        cout << "Member:" + std::to_string(m_nameAndTypeIndex) << endl;
    }

    void* ConstantMemberInfo::getValue() {
        return NULL;
    }

    void ConstantMemberInfo::readInfo(cf::ClassReader *classReader) {
        m_classIndex = classReader->readU2();
        m_nameAndTypeIndex = classReader->readU2();
    }

    string* ConstantMemberInfo::getClassName() {
        return m_cp->getClassName(m_classIndex);
    }

    NameAndType ConstantMemberInfo::getNameAndType() {
        return m_cp->getNameAndType(m_nameAndTypeIndex);
    }



    ConstantFieldRefInfo::ConstantFieldRefInfo(ConstantPool *cp) : ConstantMemberInfo(cp) {
    }

    ConstantMethodRefInfo::ConstantMethodRefInfo(cf::ConstantPool *cp) : ConstantMemberInfo(cp) {
    }

    ConstantInterfaceMethodRefInfo::ConstantInterfaceMethodRefInfo(cf::ConstantPool *cp) : ConstantMemberInfo(cp) {
    }



}