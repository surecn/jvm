//
// Created by 郑邦国 on 2018/11/22.
//

#include "OperandStrack.h"
#include "../common.h"


namespace rt {

    OperandStrack *OperandStrack::newOperandStrack(int maxStack) {
        return new OperandStrack();
    }

    void OperandStrack::pushInt(long val) {
        slot[size] = val;
        size++;
    }

    long OperandStrack::popInt() {
        size--;
        return slot[size];
    }

    void OperandStrack::pushLong(long long val) {
        slot[size] = (long)val;
        slot[size + 1] = (long)(val >> 32);
        slot+=2;
    }

    long long OperandStrack::popLong() {
        size-=2;
        return slot[size] | slot[size + 1] << 32;
    }

    float OperandStrack::popFloat() {
        size--;
        long intVal = slot[size];
        u1 data[SIZE_INT];
        BytesUtils::intToBytes(intVal, data);
        return BytesUtils::bytesToFloat(data);
    }

    void OperandStrack::pushFloat(float val) {
        u1 data[SIZE_INT];
        BytesUtils::floatToBytes(val, data);
        slot[size] = BytesUtils::bytesToInt(data);
    }

    void OperandStrack::pushDouble(double val) {
        u1 data[SIZE_INT * 2];
        BytesUtils::doubleToBytes(val, data);
        slot[size] = BytesUtils::bytesToInt(data);
        slot[size + 1] = BytesUtils::bytesToInt(data + SIZE_INT);
    }

    double OperandStrack::popDouble() {
        size-=2;
        u1 data[SIZE_INT * 2];
        BytesUtils::intToBytes(slot[size], data);
        BytesUtils::intToBytes(slot[size + 1], data + SIZE_INT);
        return BytesUtils::bytesToDouble(data);
    }

    void OperandStrack::pushRef(void *ptr) {
        slot[size] = (long)ptr;
        size++;
    }

    void* OperandStrack::popRef() {
        size--;
        return (void*)slot[size];
    }

}