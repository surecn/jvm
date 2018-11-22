cmake_minimum_required(VERSION 3.12)
project(jvm)

set(CMAKE_CXX_STANDARD 11)

add_executable(jvm main.cpp
        classpath/ClassPath.cpp classpath/ClassPath.h
        MainParamater.cpp MainParamater.h
        classpath/Entry.cpp classpath/Entry.h
        common.h
        classfile/ClassReader.cpp classfile/ClassReader.h
        classfile/ClassFile.cpp classfile/ClassFile.h
        classfile/MemberInfo.cpp classfile/MemberInfo.h
        classfile/ConstantPool.cpp classfile/ConstantPool.h
        classfile/FieldInfo.cpp classfile/FieldInfo.h
        classfile/ConstantInfo.cpp classfile/ConstantInfo.h
        classfile/ConstantIntegerInfo.cpp classfile/ConstantIntegerInfo.h
        classfile/ConstantLongInfo.cpp classfile/ConstantLongInfo.h
        classfile/ConstantFloatInfo.cpp classfile/ConstantFloatInfo.h
        classfile/ConstantDoubleInfo.cpp classfile/ConstantDoubleInfo.h
        classfile/ConstantUtf8Info.cpp classfile/ConstantUtf8Info.h
        classfile/ConstantStringInfo.cpp classfile/ConstantStringInfo.h
        classfile/ConstantClassInfo.cpp classfile/ConstantClassInfo.h
        classfile/ConstantNameAndTypeInfo.cpp classfile/ConstantNameAndTypeInfo.h
        classfile/ConstantFieldRefInfo.cpp classfile/ConstantFieldRefInfo.h
        classfile/ConstantMethodInfo.cpp classfile/ConstantMethodInfo.h
        classfile/ConstantMemberInfo.cpp classfile/ConstantMemberInfo.h
        attribute/AttributeInfo.cpp attribute/AttributeInfo.h
        common/StrUtils.h common/StrUtils.cpp classfile/ConstantFactory.cpp classfile/ConstantFactory.h attribute/CodeAttribute.cpp attribute/CodeAttribute.h attribute/ConstantValueAttribute.cpp attribute/ConstantValueAttribute.h attribute/LineNumberAttribute.cpp attribute/LineNumberAttribute.h attribute/ExceptionAttribute.cpp attribute/ExceptionAttribute.h attribute/LocalVariableTableAttribute.cpp attribute/LocalVariableTableAttribute.h attribute/SourceFileAttribute.cpp attribute/SourceFileAttribute.h attribute/UnparsedAttribute.cpp attribute/UnparsedAttribute.h runtime/Thread.cpp runtime/Thread.h runtime/Frame.cpp runtime/Frame.h runtime/Strack.cpp runtime/Strack.h runtime/LocalVars.cpp runtime/LocalVars.h runtime/OperandStrack.cpp runtime/OperandStrack.h)