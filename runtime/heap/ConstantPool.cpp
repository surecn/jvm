//
// Created by 郑邦国 on 2018/12/20.
//

#include "ConstantPool.h"

namespace rt {

    ConstantPool::ConstantPool(rt::Class *cls, cf::ConstantPool *cfCp) {
        m_consts = new Constant[cfCp->getConstantSize()];
        cf::ConstantInfo *constantInfo;
        for (int i = 0, len = cfCp->getConstantSize(); i < len; ++i) {
            constantInfo = cfCp->getConstantInfo(i);
            switch (constantInfo->m_type) {
                case cf::CONSTANT_Integer:
                    m_consts[i] = constantInfo->getValue();
                    break;
                case cf::CONSTANT_FLoat:
                    m_consts[i] = constantInfo->getValue();
                    break;
                case cf::CONSTANT_Long:
                    m_consts[i] = constantInfo->getValue();
                    break;
                case cf::CONSTANT_Double:
                    m_consts[i] = constantInfo->getValue();
                    break;
                case cf::CONSTANT_String:
                    m_consts[i] = constantInfo->getValue();
                    break;
                case cf::CONSTANT_Class:
                    //consts[i] = constantInfo->getValue();
                    break;
                case cf::CONSTANT_Fieldref:
                    //consts[i] = constantInfo->getValue();
                    break;
                case cf::CONSTANT_Methodref:
                    //consts[i] = constantInfo->getValue();
                    break;
                case cf::CONSTANT_InterfaceMethodRef:
                    //consts[i] = constantInfo->getValue();
                    break;
            }
        }
    }

    Constant ConstantPool::getConstant(u4 index) {
        Constant constant = m_consts[index];
        if (constant == NULL) {
            cout << "No constants at index " << index << endl;
        }
        return constant;
    }

    Class* ConstantPool::getClass() {
        return m_class;
    }

}