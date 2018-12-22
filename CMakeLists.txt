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
        classfile/attribute/AttributeInfo.cpp classfile/attribute/AttributeInfo.h
        common/StrUtils.h common/StrUtils.cpp
        classfile/attribute/CodeAttribute.cpp classfile/attribute/CodeAttribute.h
        classfile/attribute/ConstantValueAttribute.cpp classfile/attribute/ConstantValueAttribute.h
        classfile/attribute/LineNumberAttribute.cpp classfile/attribute/LineNumberAttribute.h
        classfile/attribute/ExceptionAttribute.cpp classfile/attribute/ExceptionAttribute.h
        classfile/attribute/LocalVariableTableAttribute.cpp classfile/attribute/LocalVariableTableAttribute.h
        classfile/attribute/SourceFileAttribute.cpp classfile/attribute/SourceFileAttribute.h
        classfile/attribute/UnparsedAttribute.cpp classfile/attribute/UnparsedAttribute.h
        runtime/Thread.cpp runtime/Thread.h
        runtime/Frame.cpp runtime/Frame.h
        runtime/Stack.cpp runtime/Stack.h
        runtime/LocalVars.cpp runtime/LocalVars.h
        runtime/OperandStack.cpp runtime/OperandStack.h
        instructions/base/Instruction.cpp instructions/base/Instruction.h
        instructions/base/BytecodeReader.cpp instructions/base/BytecodeReader.h
        instructions/constants/Constant.cpp instructions/constants/Constant.h
        common/BytesUtils.cpp common/BytesUtils.h
        classfile/Constants.cpp classfile/Constants.h instructions/loads/ILoad.cpp instructions/loads/ILoad.h instructions/stack/Pop.cpp instructions/stack/Pop.h instructions/stack/Dup.cpp instructions/stack/Dup.h instructions/stack/Swap.cpp instructions/stack/Swap.h instructions/math/Rem.cpp instructions/math/Rem.h instructions/math/Sh.cpp instructions/math/Sh.h instructions/math/And.cpp instructions/math/And.h instructions/math/IINC.cpp instructions/math/IINC.h instructions/conversions/D2x.cpp instructions/conversions/D2x.h instructions/conversions/I2x.cpp instructions/conversions/I2x.h instructions/conversions/F2x.cpp instructions/conversions/F2x.h instructions/conversions/L2x.cpp instructions/conversions/L2x.h instructions/comparisons/Lcmp.cpp instructions/comparisons/Lcmp.h instructions/comparisons/Fcmp.cpp instructions/comparisons/Fcmp.h instructions/comparisons/Dcmp.cpp instructions/comparisons/Dcmp.h instructions/comparisons/Icmp.cpp instructions/comparisons/Icmp.h instructions/comparisons/Ifcond.cpp instructions/comparisons/Ifcond.h instructions/comparisons/IF_ICMP.cpp instructions/comparisons/IF_ICMP.h instructions/comparisons/IF_ACMP.cpp instructions/comparisons/IF_ACMP.h instructions/control/Goto.cpp instructions/control/Goto.h instructions/control/TableSwitch.cpp instructions/control/TableSwitch.h instructions/control/LookupSwitch.cpp instructions/control/LookupSwitch.h instructions/extended/Wide.cpp instructions/extended/Wide.h instructions/loads/ALoad.cpp instructions/loads/ALoad.h instructions/loads/DLoad.cpp instructions/loads/DLoad.h instructions/loads/FLoad.cpp instructions/loads/FLoad.h instructions/loads/LLoad.cpp instructions/loads/LLoad.h instructions/stores/AStore.cpp instructions/stores/AStore.h instructions/stores/DStore.cpp instructions/stores/DStore.h instructions/stores/FStore.cpp instructions/stores/FStore.h instructions/stores/IStore.cpp instructions/stores/IStore.h instructions/stores/LStore.cpp instructions/stores/LStore.h instructions/extended/IFNull.cpp instructions/extended/IFNull.h instructions/extended/IFNonNull.cpp instructions/extended/IFNonNull.h instructions/extended/GotoW.cpp instructions/extended/GotoW.h Interperter.cpp Interperter.h instructions/Factory.cpp instructions/Factory.h instructions/math/Add.cpp instructions/math/Add.h instructions/math/Div.cpp instructions/math/Div.h instructions/math/Mul.cpp instructions/math/Mul.h instructions/math/Neg.cpp instructions/math/Neg.h instructions/math/Or.cpp instructions/math/Or.h instructions/math/Sub.cpp instructions/math/Sub.h instructions/math/Xor.cpp instructions/math/Xor.h instructions/constants/Ipush.cpp instructions/constants/Ipush.h instructions/constants/SIPUSH.cpp instructions/constants/SIPUSH.h runtime/heap/Class.cpp runtime/heap/Class.h runtime/heap/AccessFlags.h runtime/heap/ClassMember.cpp runtime/heap/ClassMember.h runtime/heap/Field.cpp runtime/heap/Field.h runtime/heap/Method.cpp runtime/heap/Method.h runtime/heap/ConstantPool.cpp runtime/heap/ConstantPool.h runtime/heap/SymRef.cpp runtime/heap/SymRef.h runtime/heap/ClassRef.cpp runtime/heap/ClassRef.h runtime/heap/MemberRef.cpp runtime/heap/MemberRef.h runtime/heap/FieldRef.cpp runtime/heap/FieldRef.h runtime/heap/MethodRef.cpp runtime/heap/MethodRef.h runtime/heap/InterfaceMethodRef.cpp runtime/heap/InterfaceMethodRef.h runtime/heap/ClassLoader.cpp runtime/heap/ClassLoader.h common/SlotArray.cpp common/SlotArray.h)