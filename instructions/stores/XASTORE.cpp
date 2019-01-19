//
// Created by 郑邦国 on 2019/1/5.
//

#include "XASTORE.h"
#include "../../runtime/heap/Object.h"

namespace rt {


    void AASTORE::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_ref val = stack->popRef();
        java_int index = stack->popInt();
        Object *ref = (Object *)stack->popRef();
        if (ref == NULL) {
            logError("java.lang.NullPointerException");
        }
        refArray data = ref->getRefs();
        java_int length = ref->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        data[index] = val;
    }

    void BASTORE::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_byte val = stack->popInt();
        java_int index = stack->popInt();
        Object *ref = (Object *)stack->popRef();
        if (ref == NULL) {
            logError("java.lang.NullPointerException");
        }
        byteArray data = ref->getBytes();
        java_int length = ref->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        data[index] = val;
    }


    void CASTORE::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_char val = stack->popInt();
        java_int index = stack->popInt();
        Object *ref = (Object *)stack->popRef();
        if (ref == NULL) {
            logError("java.lang.NullPointerException");
        }
        charArray data = ref->getChars();
        java_int length = ref->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        data[index] = val;
    }

    void DASTORE::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_double val = stack->popDouble();
        java_int index = stack->popInt();
        Object *ref = (Object *)stack->popRef();
        if (ref == NULL) {
            logError("java.lang.NullPointerException");
        }
        doubleArray data = ref->getDoubles();
        java_int length = ref->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        data[index] = val;
    }

    void FASTORE::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_float val = stack->popFloat();
        java_int index = stack->popInt();
        Object *ref = (Object *)stack->popRef();
        if (ref == NULL) {
            logError("java.lang.NullPointerException");
        }
        floatArray data = ref->getFloats();
        java_int length = ref->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        data[index] = val;
    }

    void IASTORE::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int val = stack->popInt();
        java_int index = stack->popInt();
        Object *ref = (Object *)stack->popRef();
        if (ref == NULL) {
            logError("java.lang.NullPointerException");
        }
        intArray data = ref->getInts();
        java_int length = ref->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        data[index] = val;
    }


    void LASTORE::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_long val = stack->popLong();
        java_int index = stack->popInt();
        Object *ref = (Object *)stack->popRef();
        if (ref == NULL) {
            logError("java.lang.NullPointerException");
        }
        longArray data = ref->getLongs();
        java_int length = ref->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        data[index] = val;
    }

    void SASTORE::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_short val = stack->popInt();
        java_int index = stack->popInt();
        Object *ref = (Object *)stack->popRef();
        if (ref == NULL) {
            logError("java.lang.NullPointerException");
        }
        shortArray data = ref->getShorts();
        java_int length = ref->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        data[index] = val;
    }
}