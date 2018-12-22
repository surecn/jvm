//
// Created by 郑邦国 on 2018/11/23.
//

#include "Constants.h"

namespace cf {

#include <typeinfo>

    ConstantFloatInfo::ConstantFloatInfo(ClassReader *classReader) {
        m_value = classReader->readU4();
    }

    void ConstantFloatInfo::print() {
        cout << "float:" + std::to_string(m_value) << endl;
    }

    void* ConstantFloatInfo::getValue() {
        return &m_value;
    }

    ConstantDoubleInfo::ConstantDoubleInfo(ClassReader *classReader) {
        m_value = classReader->readU8();
    }

    void ConstantDoubleInfo::print() {
        cout << "double:" + std::to_string(m_value) << endl;
    }

    void* ConstantDoubleInfo::getValue() {
        return &m_value;
    }

    ConstantClassInfo::ConstantClassInfo(ClassReader *classReader, ConstantPool *cp) : m_constantPool(cp){
        m_nameIndex = classReader->readU2();
    }

    string* ConstantClassInfo::getName() {
        return m_constantPool->getUtf8(m_nameIndex);
    }

    void ConstantClassInfo::print() {
        cout << "Class:" + std::to_string(m_nameIndex) << endl;
    }

    void* ConstantClassInfo::getValue() {
        return NULL;
    }

    ConstantIntegerInfo::ConstantIntegerInfo(ClassReader *classReader) {
        m_value = classReader->readU4();
    }

    void ConstantIntegerInfo::print() {
        cout << "integer:" + std::to_string(m_value) << endl;
    }

    void* ConstantIntegerInfo::getValue() {
        return &m_value;
    }

    ConstantLongInfo::ConstantLongInfo(ClassReader *classReader) {
        m_value = classReader->readU8();
    }

    void ConstantLongInfo::print() {
        cout << "long:" + std::to_string(m_value) << endl;
    }

    void* ConstantLongInfo::getValue() {
        return &m_value;
    }

    ConstantMemberInfo::ConstantMemberInfo(ClassReader *classReader, ConstantPool *cp) : m_constantPool(cp) {
        m_classIndex = classReader->readU2();
        m_nameAndTypeIndex = classReader->readU2();
    }

    void ConstantMemberInfo::print() {
        cout << "Member:" + std::to_string(m_nameAndTypeIndex) << endl;
    }

    void* ConstantMemberInfo::getValue() {
        return NULL;
    }

    string* ConstantMemberInfo::getClassName() {
        m_constantPool->getClassName(m_classIndex);
    }

    NameAndType ConstantMemberInfo::getNameAndType() {
        return m_constantPool->getNameAndType(m_nameAndTypeIndex);
    }

    ConstantInfo* ConstantFieldRefInfo::readInfo(ClassReader *classReader, ConstantPool cp) {

    }

    void* ConstantFieldRefInfo::getValue() {
        return NULL;
    }

    ConstantInfo* ConstantMethodRefInfo::readInfo(ClassReader *classReader, ConstantPool cp) {

    }

    void* ConstantMethodRefInfo::getValue() {
        return NULL;
    }

    ConstantInfo* ConstantInterfaceMethodRefInfo::readInfo(ClassReader *classReader, ConstantPool cp) {

    }

    void* ConstantInterfaceMethodRefInfo::getValue() {
        return NULL;
    }

    ConstantNameAndTypeInfo::ConstantNameAndTypeInfo(ClassReader *classReader, ConstantPool *cp) : constantPool(cp) {
        m_name_index = classReader->readU2();
        m_desciptor_index = classReader->readU2();
    }

    void ConstantNameAndTypeInfo::print() {
        cout << "NameAndType:" + std::to_string(m_name_index) << endl;
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

    ConstantStringInfo::ConstantStringInfo(ClassReader *classReader, ConstantPool *cp) : m_constantPool(cp) {
        m_stringIndex = classReader->readU2();
    }

    void ConstantStringInfo::print() {
        cout << "string:" + m_stringIndex << endl;
    }

    void* ConstantStringInfo::getValue() {
        return m_constantPool->getUtf8(m_stringIndex);
    }

    ConstantUtf8Info::ConstantUtf8Info(ClassReader *classReader) {
        m_bytes = classReader->readString();
    }

    string* ConstantUtf8Info::value() {
        return &m_bytes;
    }

    void* ConstantUtf8Info::getValue() {
        return &m_bytes;
    }

    void ConstantUtf8Info::print() {
        cout << "UTF8:" << m_bytes << endl;
    }

    u2 MemberInfo::getNameIndex() {
        return m_nameIndex;
    };

    MemberInfo::MemberInfo(ConstantPool *cp, ClassReader *classReader):m_constantPool(cp) {
        m_accessFlags = classReader->readU2();
        m_nameIndex = classReader->readU2();
        cout << "MemberInfo:" << *(cp->getUtf8(m_nameIndex)) << endl;
        m_descriptorIndex = classReader->readU2();
        m_attributeCount = classReader->readU2();
        m_attributeInfos = AttributeInfo::readAttributes(classReader, m_constantPool, m_attributeCount);
    }

    MemberInfo** MemberInfo::readMembers(ConstantPool *constantPool, ClassReader *reader, u2 *count) {
        *count = reader->readU2();
        MemberInfo** fields = new MemberInfo*[*count];
        for (int i = 0; i < *count; i++) {
            fields[i] = new MemberInfo(constantPool, reader);
        }
        return fields;
    }

    u2 MemberInfo::getDescriptorIndex() {
        return m_descriptorIndex;
    };

    CodeAttribute* MemberInfo::getCodeAttribute() {
        for (int i = 0, len = m_attributeCount; i < len; ++i) {
            cout << "\ntype:" << typeid(m_attributeInfos[i]).name() << endl;
            cout << "type:" << typeid(CodeAttribute*).name() << endl;
            if (m_attributeInfos[i]->getAttributeType() == "Code") {
                return (CodeAttribute*)(m_attributeInfos[i]);
            }
        }
        return NULL;
    }

    u2 MemberInfo::getAccessFlags() {
        return m_accessFlags;
    }

    string* MemberInfo::getName() {
        return m_constantPool->getUtf8(this->m_nameIndex);
    }

    string* MemberInfo::getDescriptor() {
        return m_constantPool->getUtf8(this->m_descriptorIndex);
    }

    ConstantInfo* ConstantFactory::readConstantInfo(ClassReader *classReader, ConstantPool *constantPool) {
        u1 tag = classReader->readU1();
        return newConstantInfo(tag, constantPool, classReader);
    }

    ConstantInfo* ConstantFactory::newConstantInfo(u1 tag, ConstantPool *constantPool, ClassReader *classReader) {
        switch (tag) {
            case CONSTANT_Integer:
                return new ConstantIntegerInfo(classReader);
            case CONSTANT_Long:
                return new ConstantLongInfo(classReader);
            case CONSTANT_FLoat:
                return new ConstantFloatInfo(classReader);
            case CONSTANT_Double:
                return new ConstantDoubleInfo(classReader);
            case CONSTANT_Utf8:
                return new ConstantUtf8Info(classReader);
            case CONSTANT_String:
                return new ConstantStringInfo(classReader, constantPool);
            case CONSTANT_Class:
                return new ConstantClassInfo(classReader, constantPool);
            case CONSTANT_NameAndType:
                return new ConstantNameAndTypeInfo(classReader, constantPool);
            case CONSTANT_Methodref:
                return new ConstantMemberInfo(classReader, constantPool);
            case CONSTANT_Fieldref:
                return new ConstantMemberInfo(classReader, constantPool);
            case CONSTANT_InterfaceMethodRef:
                return new ConstantMemberInfo(classReader, constantPool);

                //是Java SE 7才添加到class文件中的，目的是支持新增的invokedynamic指令
//            case CONST_TAG_METHOD_HANDLE:
//                return null;
//            case CONST_TAG_METHOD_TYPE:
//                return null;
//            case CONST_TAG_INVOKE_DYNAMIC:
//                return null;

            default:
                cout << "constant pool tag!" << endl;
                break;
                //throw new ClassFormatError("constant pool tag!");
        }
        return NULL;

    }

}