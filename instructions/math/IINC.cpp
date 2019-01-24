//
// Created by 郑邦国 on 2018/11/30.
//

#include "IINC.h"

namespace rt {

    void IINC::setIndex(u4 index) {
        m_index = index;
    }

    void IINC::setConstant(java_int val) {
        m_const = val;
    }

    void IINC::execute(rt::Frame *frame) {
        LocalVars *localVars = frame->getLocalVars();
        java_int val = localVars->getInt(m_index);
        val += m_const;
        cout << "IINC:" << val << "  const " << m_const << endl;
        localVars->setInt(m_index, val);
    }

    void IINC::fetchOperand(rt::BytecodeReader *reader) {
        m_index = uint(reader->readU1());
        m_const = java_int(reader->readC1());
    }


}