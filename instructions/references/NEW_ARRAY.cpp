//
// Created by 郑邦国 on 2019/1/4.
//

#include "NEW_ARRAY.h"
#include "../../runtime/heap/ClassLoader.h"
#include "../../runtime/heap/ArrayClass.h"

namespace rt {

    void NEW_ARRAY::fetchOperand(rt::BytecodeReader *reader) {
        NEW_ARRAY::atype = reader->readU1();
    }

    void NEW_ARRAY::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int count = stack->popInt();
        if (count < 0) {
            logError("java.lang.NegativeArraySizeException");
        }
        ClassLoader *classLoader = frame->getMethod()->getClass()->getClassLoader();
        ArrayClass *arrClass = (ArrayClass*)getPrimitiveArrayClass(classLoader, NEW_ARRAY::atype);
        Object *arr = arrClass->newArrayObject(count);
        stack->pushRef(arr);
    }

    Class* NEW_ARRAY::getPrimitiveArrayClass(rt::ClassLoader *loader, java_char atype) {
        switch (atype) {
            case AT_BOOLEAN: {
                string s("[Z");
                return loader->loadClass(&s);
            }
            case AT_BYTE: {
                string s("[B");
                return loader->loadClass(&s);
            }
            case AT_CHAR: {
                string s("[C");
                return loader->loadClass(&s);
            }
            case AT_SHORT: {
                string s("[S");
                return loader->loadClass(&s);
            }
            case AT_INT: {
                string s("[I");
                return loader->loadClass(&s);
            }
            case AT_LONG: {
                string s("[L");
                return loader->loadClass(&s);
            }
            case AT_FLOAT: {
                string s("[F");
                return loader->loadClass(&s);
            }
            case AT_DOUBLE: {
                string s("[D");
                return loader->loadClass(&s);
            }
            default:
                logError("Invalid atype!");
        }
        return NULL;
    }


}