//
// Created by 郑邦国 on 2018/11/22.
//

#include "OperandStack.h"
#include "../common.h"


namespace rt {

    OperandStack *OperandStack::newOperandStrack(int maxStack) {
        return new OperandStack(maxStack);
    }

    void OperandStack::pushInt(java_int val) {
        slots[size] = val;
        size++;
    }

    java_int OperandStack::popInt() {
        size--;
        return slots[size];
    }

    void OperandStack::pushLong(java_long val) {
        slots[size] = (long)val;
        slots[size + 1] = (long)(val >> 32);
        slots+=2;
    }

    java_long OperandStack::popLong() {
        size-=2;
        return slots[size] | slots[size + 1] << 32;
    }

    java_float OperandStack::popFloat() {
        size--;
        long intVal = slots[size];
        u1 data[SIZE_INT];
        BytesUtils::intToBytes(intVal, data);
        return BytesUtils::bytesToFloat(data);
    }

    void OperandStack::pushFloat(java_float val) {
        u1 data[SIZE_INT];
        BytesUtils::floatToBytes(val, data);
        slots[size] = BytesUtils::bytesToInt(data);
    }

    void OperandStack::pushDouble(java_double val) {
        u1 data[SIZE_INT * 2];
        BytesUtils::doubleToBytes(val, data);
        slots[size] = BytesUtils::bytesToInt(data);
        slots[size + 1] = BytesUtils::bytesToInt(data + SIZE_INT);
    }

    java_double OperandStack::popDouble() {
        size-=2;
        u1 data[SIZE_INT * 2];
        BytesUtils::intToBytes(slots[size], data);
        BytesUtils::intToBytes(slots[size + 1], data + SIZE_INT);
        return BytesUtils::bytesToDouble(data);
    }

    void OperandStack::pushRef(java_ref ptr) {
        slots[size] = (long)ptr;
        size++;
    }

    java_ref OperandStack::popRef() {
        size--;
        return (void*)slots[size];
    }

    void OperandStack::pushSlot(java_int slot) {
        slots[size] = slot;
        size++;
    }

    java_int OperandStack::popSlot() {
        size--;
        return slots[size];
    }

}