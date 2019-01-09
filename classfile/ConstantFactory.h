//
// Created by 郑邦国 on 2018/11/21.
//

#ifndef JVM_CONSTANTFACTORY_H
#define JVM_CONSTANTFACTORY_H


#include "../common.h"
#include "ConstantInfo.h"
#include "ConstantLongInfo.h"
#include "ConstantIntegerInfo.h"
#include "ConstantFloatInfo.h"
#include "ConstantDoubleInfo.h"
#include "ConstantUtf8Info.h"
#include "ConstantStringInfo.h"
#include "ConstantClassInfo.h"
#include "ConstantNameAndTypeInfo.h"
#include "ConstantMemberInfo.h"


class ConstantFactory {

public:

    static ConstantInfo* readConstantInfo(ClassReader* classReader, ConstantPool* constantPool) {
        u1 tag = classReader->readU1();
        return newConstantInfo(tag, constantPool, classReader);
    }

    static ConstantInfo* newConstantInfo(u1 tag, ConstantPool *constantPool, ClassReader *classReader) {
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
                break;
                //throw new ClassFormatError("constant pool tag!");
        }
        return NULL;

    }
};


#endif //JVM_CONSTANTFACTORY_H
