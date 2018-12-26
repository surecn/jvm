//
// Created by 郑邦国 on 2018/12/20.
//

#include "ConstantPool.h"
#include "ClassRef.h"
#include "FieldRef.h"
#include "MethodRef.h"
#include "InterfaceMethodRef.h"

namespace rt {

    ConstantPool::ConstantPool(rt::Class *cls, cf::ConstantPool *cfCp) {
        m_consts = new Constant[cfCp->getConstantSize()];
        m_class = cls;
        cf::ConstantInfo *constantInfo;
        for (int i = 1, len = cfCp->getConstantSize(); i < len; ++i) {
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
                case cf::CONSTANT_Class: {
                    cf::ConstantClassInfo *constantClassInfo = (cf::ConstantClassInfo *) constantInfo;
                    m_consts[i] = new ClassRef(this, constantClassInfo);
                    break;
                }
                case cf::CONSTANT_Fieldref: {
                    cf::ConstantFieldRefInfo *constantFieldRefInfo = (cf::ConstantFieldRefInfo *) constantInfo;
                    m_consts[i] = new FieldRef(this, constantFieldRefInfo);
                    break;
                }
                case cf::CONSTANT_Methodref: {
                    cf::ConstantMethodRefInfo *constantMethodRefInfo = (cf::ConstantMethodRefInfo *) constantInfo;
                    m_consts[i] = new MethodRef(this, constantMethodRefInfo);
                    break;
                }
                case cf::CONSTANT_InterfaceMethodRef: {
                    cf::ConstantInterfaceMethodRefInfo *interfaceMethodRefInfo = (cf::ConstantInterfaceMethodRefInfo *) constantInfo;
                    m_consts[i] = new InterfaceMethodRef(this, interfaceMethodRefInfo);
                    break;
                }
                default:
                    //todo
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