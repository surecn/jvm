//
// Created by 郑邦国 on 2018/11/23.
//

#include "Constants.h"
#include "ConstantNumeric.h"
#include "ConstantInvokeDynamic.h"


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

    void ConstantUtf8Info::readInfo(cf::ClassReader *classReader) {
        m_utf8 = classReader->readString();
    }

    string* ConstantUtf8Info::value() {
        return m_utf8;
    }

    void* ConstantUtf8Info::getValue() {
        return m_utf8;
    }

    void ConstantUtf8Info::print() {
        //cout << "UTF8:" << *m_utf8 << endl;
    }

    MemberInfo::~MemberInfo() {
        delete [] m_attributeInfos;
    }

    u2 MemberInfo::getNameIndex() {
        return m_nameIndex;
    };

    MemberInfo::MemberInfo(ConstantPool *cp, ClassReader *classReader):m_constantPool(cp) {
        m_accessFlags = classReader->readU2();
        m_nameIndex = classReader->readU2();
        //cout << "MemberInfo:" << *(cp->getUtf8(m_nameIndex)) << endl;
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

    ConstantValueAttribute* MemberInfo::getConstantValueAttribute() {
        for (int i = 0, len = m_attributeCount; i < len; ++i) {
            if ("ConstantValue" == m_attributeInfos[i]->getAttributeType()) {
                return (ConstantValueAttribute*)m_attributeInfos[i];
            }
        }
        return NULL;
    }

    ConstantInfo* ConstantFactory::readConstantInfo(ClassReader *classReader, ConstantPool *constantPool) {
        u1 tag = classReader->readU1();
        ConstantInfo *constantInfo = newConstantInfo(tag, constantPool);
        constantInfo->setType(tag);
        constantInfo->readInfo(classReader);
        return constantInfo;
    }

    ConstantInfo* ConstantFactory::newConstantInfo(u1 tag, ConstantPool *constantPool) {
        //cout << "attribute:" << (int)tag << endl;
        switch (tag) {
            case CONSTANT_Integer:
                return new ConstantIntegerInfo();
            case CONSTANT_Long:
                return new ConstantLongInfo();
            case CONSTANT_FLoat:
                return new ConstantFloatInfo();
            case CONSTANT_Double:
                return new ConstantDoubleInfo();
            case CONSTANT_Utf8:
                return new ConstantUtf8Info();
            case CONSTANT_String:
                return new ConstantStringInfo(constantPool);
            case CONSTANT_Class:
                return new ConstantClassInfo(constantPool);
            case CONSTANT_Methodref:
                return new ConstantMethodRefInfo(constantPool);
            case CONSTANT_Fieldref:
                return new ConstantFieldRefInfo(constantPool);
            case CONSTANT_InterfaceMethodRef:
                return new ConstantInterfaceMethodRefInfo(constantPool);
            case CONSTANT_NameAndType:
                return new ConstantNameAndTypeInfo(constantPool);
            case CONSTANT_MethodType:
                return new ConstantMethodTypeInfo();
                //是Java SE 7才添加到class文件中的，目的是支持新增的invokedynamic指令
            case CONSTANT_MethodHandle:
                return new ConstantMethodHandleInfo();
            case CONSTANT_InvokeDynamic:
                return new ConstantInvokeDynamicInfo();
            default:
                cout << "java.lang.ClassFormatError: constant pool tag! " << endl;
                break;
                //throw new ClassFormatError("constant pool tag!");
        }
        return NULL;

    }

}