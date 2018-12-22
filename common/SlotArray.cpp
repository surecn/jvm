//
// Created by 郑邦国 on 2018/12/22.
//

#include "SlotArray.h"

java_int SlotArray::getInt(int index) {
    return m_slots[index];
}

void SlotArray::setInt(int index, java_int val) {
    m_slots[index] = val;
}

java_float SlotArray::getFloat(int index) {
    u1 ch[SIZE_INT];
    BytesUtils::intToBytes(m_slots[index], ch);
    return BytesUtils::bytesToFloat(ch);
}

void SlotArray::setFloat(int index, java_float val) {
    u1 ch[SIZE_INT];
    BytesUtils::floatToBytes(val, ch);
    m_slots[index] = BytesUtils::bytesToInt(ch);
}

java_long SlotArray::getLong(int index) {
    java_long low = m_slots[index];
    java_long high = m_slots[index + 1];
    return high << 32 | low;
}

void SlotArray::setLong(int index, java_long val) {
    java_int low = val;
    java_int high = val >> 32;
    m_slots[index] = low;
    m_slots[index + 1] = high;
}

java_double SlotArray::getDouble(int index) {
    java_long low = m_slots[index];
    java_long high = m_slots[index + 1];
    u1 ch[SIZE_INT * 2];
    BytesUtils::intToBytes(low, ch);
    BytesUtils::intToBytes(high, ch + SIZE_INT);
    return BytesUtils::bytesToDouble(ch);
}

void SlotArray::setDouble(int index, java_double val) {
    u1 ch[SIZE_INT * 2];
    BytesUtils::doubleToBytes(val, ch);
    m_slots[index] = BytesUtils::bytesToInt(ch) + BytesUtils::bytesToInt(ch) << SIZE_INT;
}

java_ref SlotArray::getRef(int index) {
    return (java_int*)m_slots[index];
}

void SlotArray::setRef(int index, java_ref val) {
    m_slots[index] = (java_int)val;
}