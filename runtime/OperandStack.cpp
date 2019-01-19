//
// Created by 郑邦国 on 2018/11/22.
//

#include "OperandStack.h"
#include "../common.h"


namespace rt {

    OperandStack::OperandStack(java_int val, string method) {
        OperandStack::method = method;
        m_size = 0;
        m_slots = new java_int[val];
        println(" new:" + val);
    }

    void OperandStack::pushInt(java_int val) {
        println("pushInt");
        m_slots[m_size] = val;
        m_size++;
    }

    java_int OperandStack::popInt() {
        println("popInt");
        m_size--;
        return m_slots[m_size];
    }

    void OperandStack::pushLong(java_long val) {
        println("pushLong");
        m_slots[m_size] = (java_int)val;
        m_slots[m_size + 1] = (java_int)(val >> BITS_INT);
        m_size+=2;
    }

    java_long OperandStack::popLong() {
        println("popLong");
        m_size-=2;
        return m_slots[m_size] | (m_slots[m_size + 1] << BITS_INT);
    }

    java_float OperandStack::popFloat() {
        println("popFloat");
        m_size--;
        long intVal = m_slots[m_size];
        u1 data[SIZE_INT];
        BytesUtils::intToBytes(intVal, data);
        return BytesUtils::bytesToFloat(data);
    }

    void OperandStack::pushFloat(java_float val) {
        println("pushFloat");
        u1 data[SIZE_INT];
        BytesUtils::floatToBytes(val, data);
        m_slots[m_size] = BytesUtils::bytesToInt(data);
        m_size++;
    }

    void OperandStack::pushDouble(java_double val) {
        println("pushDouble");
        u1 data[SIZE_INT * 2];
        BytesUtils::doubleToBytes(val, data);
        m_slots[m_size] = BytesUtils::bytesToInt(data);
        m_slots[m_size + 1] = BytesUtils::bytesToInt(data + SIZE_INT);
        m_size+=2;
    }

    java_double OperandStack::popDouble() {
        println("popDouble");
        m_size-=2;
        u1 data[SIZE_INT * 2];
        BytesUtils::intToBytes(m_slots[m_size], data);
        BytesUtils::intToBytes(m_slots[m_size + 1], data + SIZE_INT);
        return BytesUtils::bytesToDouble(data);
    }

    void OperandStack::pushRef(java_ref ptr) {
        println("pushRef");
        m_slots[m_size] = (java_int)ptr;
        m_size++;
    }

    java_ref OperandStack::popRef() {
        println("popRef");
        m_size--;
        return (void*)m_slots[m_size];
    }

    void OperandStack::pushSlot(java_int slot) {
        println("pushSlot");
        m_slots[m_size] = slot;
        m_size++;
    }

    java_int OperandStack::popSlot() {
        println("popSlot");
        m_size--;
        return m_slots[m_size];
    }

    java_int OperandStack::getRefFromTop(int n) {
        return m_slots[m_size - 1 - n];
    }

    void OperandStack::pushBoolean(bool val) {
        pushInt(val ? 1 : 0);
    }

    bool OperandStack::popBoolean() {
        return popInt() == 1;
    }

    void OperandStack::println(string _m) {
        stringstream sstr;
        sstr << method << "  OperandStack >> " << _m << "  >>  " << m_size;
        logError(sstr.str());
    }

}