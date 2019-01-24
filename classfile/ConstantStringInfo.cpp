//
// Created by 郑邦国 on 2018/11/10.
//

#include "ConstantStringInfo.h"

namespace cf {

    ConstantStringInfo::ConstantStringInfo(ConstantPool *cp) : m_cp(cp) {
    }

    void ConstantStringInfo::readInfo(cf::ClassReader *classReader) {
        m_stringIndex = classReader->readU2();
    }

    void ConstantStringInfo::print() {
        cout << "string:" + m_stringIndex << endl;
    }

    void* ConstantStringInfo::getValue() {
        return m_cp->getUtf8(m_stringIndex);
    }

}