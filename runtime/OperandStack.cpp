//
// Created by 郑邦国 on 2018/11/22.
//

#include "OperandStack.h"
#include "../common.h"


namespace rt {

    OperandStack *OperandStack::newOperandStrack(int maxStack) {
        return new OperandStack();
    }

    void OperandStack::pushInt(long val) {
        slots[size] = val;
        size++;
    }

    long OperandStack::popInt() {
        size--;
        return slots[size];
    }

    void OperandStack::pushLong(long long val) {
        slots[size] = (long)val;
        slots[size + 1] = (long)(val >> 32);
        slots+=2;
    }

    long long OperandStack::popLong() {
        size-=2;
        return slots[size] | slots[size + 1] << 32;
    }

    float OperandStack::popFloat() {
        size--;
        long intVal = slots[size];
        u1 data[SIZE_INT];
        BytesUtils::intToBytes(intVal, data);
        return BytesUtils::bytesToFloat(data);
    }

    void OperandStack::pushFloat(float val) {
        u1 data[SIZE_INT];
        BytesUtils::floatToBytes(val, data);
        slots[size] = BytesUtils::bytesToInt(data);
    }

    void OperandStack::pushDouble(double val) {
        u1 data[SIZE_INT * 2];
        BytesUtils::doubleToBytes(val, data);
        slots[size] = BytesUtils::bytesToInt(data);
        slots[size + 1] = BytesUtils::bytesToInt(data + SIZE_INT);
    }

    double OperandStack::popDouble() {
        size-=2;
        u1 data[SIZE_INT * 2];
        BytesUtils::intToBytes(slots[size], data);
        BytesUtils::intToBytes(slots[size + 1], data + SIZE_INT);
        return BytesUtils::bytesToDouble(data);
    }

    void OperandStack::pushRef(void *ptr) {
        slots[size] = (long)ptr;
        size++;
    }

    void* OperandStack::popRef() {
        size--;
        return (void*)slots[size];
    }

    void OperandStack::pushSlot(long slot) {
        slots[size] = slot;
        size++;
    }

    long OperandStack::popSlot() {
        size--;
        return slots[size];
    }

}