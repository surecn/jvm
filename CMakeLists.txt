cmake_minimum_required(VERSION 3.12)
project(jvm)

set(CMAKE_CXX_STANDARD 11)

add_executable(jvm main.cpp common/type.h ClassPath.cpp ClassPath.h MainParamater.cpp MainParamater.h Entry.cpp Entry.h common.h ClassReader.cpp ClassReader.h ClassFile.cpp ClassFile.h MemberInfo.cpp MemberInfo.h ConstantPool.cpp ConstantPool.h AttributeInfo.cpp AttributeInfo.h FieldInfo.cpp FieldInfo.h ConstantInfo.cpp ConstantInfo.h)