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
        classfile/ConstantPool.cpp classfile/ConstantPool.h
        classfile/ConstantInfo.cpp classfile/ConstantInfo.h
        attribute/AttributeInfo.cpp attribute/AttributeInfo.h
        common/StrUtils.h common/StrUtils.cpp
        attribute/CodeAttribute.cpp attribute/CodeAttribute.h
        attribute/ConstantValueAttribute.cpp attribute/ConstantValueAttribute.h
        attribute/LineNumberAttribute.cpp attribute/LineNumberAttribute.h
        attribute/ExceptionAttribute.cpp attribute/ExceptionAttribute.h
        attribute/LocalVariableTableAttribute.cpp attribute/LocalVariableTableAttribute.h
        attribute/SourceFileAttribute.cpp attribute/SourceFileAttribute.h
        attribute/UnparsedAttribute.cpp attribute/UnparsedAttribute.h
        runtime/Thread.cpp runtime/Thread.h
        runtime/Frame.cpp runtime/Frame.h
        runtime/Stack.cpp runtime/Stack.h
        runtime/LocalVars.cpp runtime/LocalVars.h
        runtime/OperandStack.cpp runtime/OperandStack.h
        instructions/Instruction.cpp instructions/Instruction.h
        instructions/BytecodeReader.cpp instructions/BytecodeReader.h
        instructions/Constant.cpp instructions/Constant.h
        common/BytesUtils.cpp common/BytesUtils.h
        classfile/Constants.cpp classfile/Constants.h instructions/IPush.cpp instructions/IPush.h instructions/ILoad.cpp instructions/ILoad.h instructions/IStore.cpp instructions/IStore.h instructions/stack/Pop.cpp instructions/stack/Pop.h instructions/stack/Dup.cpp instructions/stack/Dup.h instructions/stack/Swap.cpp instructions/stack/Swap.h instructions/stack/Math.cpp instructions/stack/Math.h)