//
// Created by 郑邦国 on 2018/11/22.
//

#include "OperandStack.h"
#include "../common.h"


namespace rt {

    OperandStack::OperandStack(java_int val) {
        m_size = 0;
        m_slots = new java_int[val];
    }

    void OperandStack::pushInt(java_int val) {
        m_slots[m_size] = val;
        m_size++;
    }

    java_int OperandStack::popInt() {
        m_size--;
        return m_slots[m_size];
    }

    void OperandStack::pushLong(java_long val) {
        m_slots[m_size] = (long)val;
        m_slots[m_size + 1] = (long)(val >> 32);
        m_size+=2;
    }

    java_long OperandStack::popLong() {
        m_size-=2;
        return m_slots[m_size] | m_slots[m_size + 1] << 32;
    }

    java_float OperandStack::popFloat() {
        m_size--;
        long intVal = m_slots[m_size];
        u1 data[SIZE_INT];
        BytesUtils::intToBytes(intVal, data);
        return BytesUtils::bytesToFloat(data);
    }

    void OperandStack::pushFloat(java_float val) {
        u1 data[SIZE_INT];
        BytesUtils::floatToBytes(val, data);
        m_slots[m_size] = BytesUtils::bytesToInt(data);
        m_size++;
    }

    void OperandStack::pushDouble(java_double val) {
        u1 data[SIZE_INT * 2];
        BytesUtils::doubleToBytes(val, data);
        m_slots[m_size] = BytesUtils::bytesToInt(data);
        m_slots[m_size + 1] = BytesUtils::bytesToInt(data + SIZE_INT);
        m_size+=2;
    }

    java_double OperandStack::popDouble() {
        m_size-=2;
        u1 data[SIZE_INT * 2];
        BytesUtils::intToBytes(m_slots[m_size], data);
        BytesUtils::intToBytes(m_slots[m_size + 1], data + SIZE_INT);
        return BytesUtils::bytesToDouble(data);
    }

    void OperandStack::pushRef(java_ref ptr) {
        m_slots[m_size] = (long)ptr;
        m_size++;
    }

    java_ref OperandStack::popRef() {
        m_size--;
        return (void*)m_slots[m_size];
    }

    void OperandStack::pushSlot(java_int slot) {
        m_slots[m_size] = slot;
        m_size++;
    }

    java_int OperandStack::popSlot() {
        m_size--;
        return m_slots[m_size];
    }

}