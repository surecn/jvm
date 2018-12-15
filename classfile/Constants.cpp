//
// Created by 郑邦国 on 2018/11/23.
//

#include "Constants.h"

namespace cls {

    ConstantFloatInfo::ConstantFloatInfo(cls::ClassReader *classReader) {
        value = classReader->readU4();
    }

    void ConstantFloatInfo::print() {
        cout << "float:" + std::to_string(value) << endl;
    }

    ConstantInfo* ConstantFieldRefInfo::readInfo(cls::ClassReader *classReader, cls::ConstantPool cp) {

    }

    ConstantDoubleInfo::ConstantDoubleInfo(cls::ClassReader *classReader) {
        value = classReader->readU8();
    }

    void ConstantDoubleInfo::print() {
        cout << "double:" + std::to_string(value) << endl;
    }

    ConstantClassInfo::ConstantClassInfo(cls::ClassReader *classReader, cls::ConstantPool *cp) : constantPool(cp){
        nameIndex = classReader->readU2();
    }

    string* ConstantClassInfo::getName() {
        return constantPool->getUtf8(nameIndex);
    }

    void ConstantClassInfo::print() {
        cout << "Class:" + std::to_string(nameIndex) << endl;
    }

    ConstantIntegerInfo::ConstantIntegerInfo(cls::ClassReader *classReader) {
        value = classReader->readU4();
    }

    void ConstantIntegerInfo::print() {
        cout << "integer:" + std::to_string(value) << endl;
    }

    ConstantLongInfo::ConstantLongInfo(cls::ClassReader *classReader) {
        value = classReader->readU8();
    }

    void ConstantLongInfo::print() {
        cout << "long:" + std::to_string(value) << endl;
    }

    ConstantMemberInfo::ConstantMemberInfo(cls::ClassReader *classReader, cls::ConstantPool *cp) : constantPool(cp) {
        classIndex = classReader->readU2();
        nameAndTypeIndex = classReader->readU2();
    }

    void ConstantMemberInfo::print() {
        cout << "Member:" + std::to_string(nameAndTypeIndex) << endl;
    }

    ConstantNameAndTypeInfo::ConstantNameAndTypeInfo(cls::ClassReader *classReader, cls::ConstantPool *cp) : constantPool(cp) {
        nameIndex = classReader->readU2();
        desciptorIndex = classReader->readU2();
    }

    void ConstantNameAndTypeInfo::print() {
        cout << "NameAndType:" + std::to_string(nameIndex) << endl;
    }

    ConstantStringInfo::ConstantStringInfo(cls::ClassReader *classReader, cls::ConstantPool *cp) : constantPool(cp) {
        stringIndex = classReader->readU2();
    }

    void ConstantStringInfo::print() {
        cout << "string:" + stringIndex << endl;
    }

    ConstantUtf8Info::ConstantUtf8Info(cls::ClassReader *classReader) {
        bytes = classReader->readString();
    }

    string* ConstantUtf8Info::value() {
        return &bytes;
    }

    void ConstantUtf8Info::print() {
        cout << "UTF8:" << bytes << endl;
    }


    u2 MemberInfo::getNameIndex() {
        return nameIndex;
    };

    MemberInfo::MemberInfo(ConstantPool *cp, ClassReader *classReader):constantPool(cp) {
        accessFlags = classReader->readU2();
        nameIndex = classReader->readU2();
        cout << "MemberInfo:" << *(cp->getUtf8(nameIndex)) << endl;
        descriptorIndex = classReader->readU2();
        attributeCount = classReader->readU2();
        attributeInfos = AttributeInfo::readAttributes(classReader, constantPool, attributeCount);
    }

    MemberInfo** MemberInfo::readMembers(ConstantPool *constantPool, ClassReader *reader) {
        u2 fieldCount = reader->readU2();
        MemberInfo** fields = new MemberInfo*[fieldCount];
        for (int i = 0; i < fieldCount; i++) {
            fields[i] = new MemberInfo(constantPool, reader);
        }

        return fields;
    }

    u2 MemberInfo::getDescriptorIndex() {
        return descriptorIndex;
    };

    CodeAttribute* MemberInfo::getCodeAttribute() {
        for (int i = 0, len = attributeCount; i < len; ++i) {
            if (typeid(attributeInfos[i]) == typeid(CodeAttribute*)) {
                return (CodeAttribute*)(attributeInfos[i]);
            }
        }
        return NULL;
    }

    ConstantInfo* ConstantFactory::readConstantInfo(cls::ClassReader *classReader, cls::ConstantPool *constantPool) {
        u1 tag = classReader->readU1();
        return newConstantInfo(tag, constantPool, classReader);
    }

    ConstantInfo* ConstantFactory::newConstantInfo(u1 tag, cls::ConstantPool *constantPool,
                                                   cls::ClassReader *classReader) {
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