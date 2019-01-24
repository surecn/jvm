//
// Created by 郑邦国 on 2019/1/5.
//

#include "XALOAD.h"
#include "../../runtime/heap/Object.h"

namespace rt {

    void AALOAD::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int index = stack->popInt();
        Object *arrRef = (Object*)stack->popRef();
        if (arrRef == NULL) {
            logError("java.lang.NullPointerException");
        }
        java_int length = arrRef->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
            return;
        }
        refArray array = arrRef->getRefs();
        stack->pushRef(array[index]);
    }

    void BALOAD::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int index = stack->popInt();
        Object *arrRef = (Object*)stack->popRef();
        if (arrRef == NULL) {
            logError("java.lang.NullPointerException");
        }
        java_int length = arrRef->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        byteArray array = arrRef->getBytes();
        stack->pushInt(array[index]);
    }

    void CALOAD::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int index = stack->popInt();
        Object *arrRef = (Object*)stack->popRef();
        if (arrRef == NULL) {
            logError("java.lang.NullPointerException");
        }
        java_int length = arrRef->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        charArray array = arrRef->getChars();
        stack->pushInt(array[index]);
    }

    void DALOAD::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int index = stack->popInt();
        Object *arrRef = (Object*)stack->popRef();
        if (arrRef == NULL) {
            logError("java.lang.NullPointerException");
        }
        java_int length = arrRef->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        doubleArray array = arrRef->getDoubles();
        stack->pushDouble(array[index]);
    }

    void FALOAD::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int index = stack->popInt();
        Object *arrRef = (Object*)stack->popRef();
        if (arrRef == NULL) {
            logError("java.lang.NullPointerException");
        }
        java_int length = arrRef->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        floatArray array = arrRef->getFloats();
        stack->pushFloat(array[index]);
    }

    void IALOAD::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int index = stack->popInt();
        Object *arrRef = (Object*)stack->popRef();
        if (arrRef == NULL) {
            logError("java.lang.NullPointerException");
        }
        java_int length = arrRef->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        intArray array = arrRef->getInts();
        stack->pushInt(array[index]);
    }

    void LALOAD::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int index = stack->popInt();
        Object *arrRef = (Object*)stack->popRef();
        if (arrRef == NULL) {
            logError("java.lang.NullPointerException");
        }
        java_int length = arrRef->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        longArray array = arrRef->getLongs();
        stack->pushLong(array[index]);
    }

    void SALOAD::execute(rt::Frame *frame) {
        OperandStack *stack = frame->getOperandStack();
        java_int index = stack->popInt();
        Object *arrRef = (Object*)stack->popRef();
        if (arrRef == NULL) {
            logError("java.lang.NullPointerException");
        }
        java_int length = arrRef->getArrayLength();
        if (index < 0 || index >= length) {
            logError("java.lang.ArrayIndexOutOfBoundsException");
        }
        shortArray array = arrRef->getShorts();
        stack->pushInt(array[index]);
    }

}