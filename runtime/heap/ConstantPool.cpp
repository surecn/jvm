//
// Created by 郑邦国 on 2018/12/20.
//

#include "ConstantPool.h"

namespace rt {

    ConstantPool::ConstantPool(rt::Class *cls, cf::ConstantPool *cfCp) {
        m_consts = new Constant*[cfCp->getConstantSize()];
        m_class = cls;
        m_size = cfCp->getConstantSize();
        cf::ConstantInfo *constantInfo;
        for (int i = 1, len = cfCp->getConstantSize(); i < len; ++i) {
            constantInfo = cfCp->getConstantInfo(i);
            //cout << *cls->getName() << " " << dec << i << "  " << constantInfo->m_type << endl;
            switch (constantInfo->m_type) {
                case cf::CONSTANT_Integer: {
                    ConstantInteger *constantInteger = new ConstantInteger();
                    constantInteger->value = *(java_int *) (constantInfo->getValue());
                    m_consts[i] = constantInteger;
                    m_consts[i]->type = constantInfo->m_type;
                    break;
                }
                case cf::CONSTANT_FLoat: {
                    ConstantFloat *constantFloat = new ConstantFloat();
                    constantFloat->value = *(java_float *) (constantInfo->getValue());
                    m_consts[i] = constantFloat;
                    m_consts[i]->type = constantInfo->m_type;
                    break;
                }
                case cf::CONSTANT_Long: {
                    ConstantLong *constantLong = new ConstantLong();
                    constantLong->value = *(java_long *) (constantInfo->getValue());
                    m_consts[i] = constantLong;
                    m_consts[i]->type = constantInfo->m_type;
                    i++;
                    break;
                }
                case cf::CONSTANT_Double: {
                    ConstantDouble *constantDouble = new ConstantDouble();
                    constantDouble->value = *(java_double *) (constantInfo->getValue());
                    m_consts[i] = constantDouble;
                    m_consts[i]->type = constantInfo->m_type;
                    i++;
                    break;
                }
                case cf::CONSTANT_String: {
                    ConstantString *constantString = new ConstantString();
                    constantString->value = *(string *) (constantInfo->getValue());
                    m_consts[i] = constantString;
                    m_consts[i]->type = constantInfo->m_type;
                    break;
                }
                case cf::CONSTANT_Class: {
                    ConstantClassRef *constantClassRef = new ConstantClassRef();
                    cf::ConstantClassInfo *constantClassInfo = (cf::ConstantClassInfo *) constantInfo;
                    constantClassRef->ref = new ClassRef(this, constantClassInfo);
                    m_consts[i] = constantClassRef;
                    m_consts[i]->type = constantInfo->m_type;
                    break;
                }
                case cf::CONSTANT_Fieldref: {
                    ConstantFieldRef *constantFieldRef = new ConstantFieldRef();
                    cf::ConstantFieldRefInfo *constantFieldRefInfo = (cf::ConstantFieldRefInfo *) constantInfo;
                    constantFieldRef->ref = new FieldRef(this, constantFieldRefInfo);
                    m_consts[i] = constantFieldRef;
                    m_consts[i]->type = constantInfo->m_type;
                    break;
                }
                case cf::CONSTANT_Methodref: {
                    ConstantMethodRef *constantMethodRef = new ConstantMethodRef();
                    cf::ConstantMethodRefInfo *constantMethodRefInfo = (cf::ConstantMethodRefInfo *) constantInfo;
                    constantMethodRef->ref = new MethodRef(this, constantMethodRefInfo);
                    m_consts[i] = constantMethodRef;
                    m_consts[i]->type = constantInfo->m_type;
                    break;
                }
                case cf::CONSTANT_InterfaceMethodRef: {
                    ConstantIngerfaceMethodRef *constantInterfaceMethodRef = new ConstantIngerfaceMethodRef();
                    cf::ConstantInterfaceMethodRefInfo *interfaceMethodRefInfo = (cf::ConstantInterfaceMethodRefInfo *) constantInfo;
                    constantInterfaceMethodRef->ref = new InterfaceMethodRef(this, interfaceMethodRefInfo);
                    m_consts[i] = constantInterfaceMethodRef;
                    m_consts[i]->type = constantInfo->m_type;
                    break;
                }
                default:
                    m_consts[i] = NULL;
                    //todo
                    break;
            }
            //delete constantInfo;
        }
        //delete cfCp;
    }

    Constant* ConstantPool::getConstant(u4 index) {
        Constant* constant = m_consts[index];
        if (constant == NULL) {
            cout << "No constants at index " << index << endl;
        }
        return constant;
    }

    ClassRef* ConstantPool::getClassRef(u4 index) {
        Constant* constant = m_consts[index];
        if (constant == NULL) {
            cout << "No constants at index " << index << endl;
        }
        return ((ConstantClassRef *)constant)->ref;
    }

    MethodRef* ConstantPool::getMethodRef(u4 index) {
        Constant* constant = m_consts[index];
        if (constant == NULL) {
            cout << "No constants at index " << index << endl;
        }
        return ((ConstantMethodRef *)constant)->ref;
    }

    FieldRef* ConstantPool::getFieldRef(u4 index) {
        Constant* constant = m_consts[index];
        if (constant == NULL) {
            cout << "No constants at index " << index << endl;
        }
        return ((ConstantFieldRef *)constant)->ref;
    }

    InterfaceMethodRef* ConstantPool::getInterfaceMethodRef(u4 index) {
        Constant* constant = m_consts[index];
        if (constant == NULL) {
            cout << "No constants at index " << index << endl;
        }
        return ((ConstantIngerfaceMethodRef *)constant)->ref;
    }

    java_int ConstantPool::getInteger(u4 index) {
        Constant* constant = m_consts[index];
        if (constant == NULL) {
            cout << "No constants at index " << index << endl;
        }
        return ((ConstantInteger *)constant)->value;
    }

    java_float ConstantPool::getFloat(u4 index) {
        Constant* constant = m_consts[index];
        if (constant == NULL) {
            cout << "No constants at index " << index << endl;
        }
        return ((ConstantFloat *)constant)->value;
    }

    java_long ConstantPool::getLong(u4 index) {
        Constant* constant = m_consts[index];
        if (constant == NULL) {
            cout << "No constants at index " << index << endl;
        }
        return ((ConstantLong *)constant)->value;
    }

    java_double ConstantPool::getDouble(u4 index) {
        Constant* constant = m_consts[index];
        if (constant == NULL) {
            cout << "No constants at index " << index << endl;
        }
        return ((ConstantDouble *)constant)->value;
    }

    string* ConstantPool::getString(u4 index) {
        Constant* constant = m_consts[index];
        if (constant == NULL) {
            cout << "No constants at index " << index << endl;
        }
        return &((ConstantString *)constant)->value;
    }

    Class* ConstantPool::getClass() {
        return m_class;
    }

}