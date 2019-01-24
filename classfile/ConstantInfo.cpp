//
// Created by 郑邦国 on 2018/11/5.
//

#include "ConstantInfo.h"
#include "attribute/AttributeInfo.h"
#include "ConstantNumeric.h"
#include "ConstantInvokeDynamic.h"
#include "ConstantUtf8Info.h"
#include "ConstantStringInfo.h"
#include "ConstantClassInfo.h"
#include "ConstantMemberInfo.h"
#include "ConstantNameAndTypeInfo.h"

namespace cf {

    void* ConstantInfo::getValue() {
        return NULL;
    }

    void ConstantInfo::print() {

    }

    void ConstantInfo::setType(int type) {
        m_type = type;
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
