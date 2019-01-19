//
// Created by 郑邦国 on 2018/12/22.
//

#include "Object.h"
#include "Class.h"

namespace rt {

    Object::Object(rt::Class *cls) {
        m_class = cls;
        m_data = new SlotArray(cls->getInstanceSlotCount());
    }

    Object::Object(rt::Class *cls, void* data, int count) {
        m_class = cls;
        m_data = data;
        m_length = count;
    }

    Class *Object::getClass() const {
        return m_class;
    }

    bool Object::isInstanceOf(rt::Class *cls) {
        return cls->isAssignableFrom(m_class);
    }

    SlotArray *Object::getFields() const {
        return static_cast<SlotArray *>(m_data);
    }

    byteArray Object::getBytes() {
        return static_cast<byteArray>(m_data);
    }

    charArray Object::getChars() {
        return static_cast<charArray>(m_data);
    }

    shortArray Object::getShorts() {
        return static_cast<shortArray>(m_data);
    }

    intArray Object::getInts() {
        return static_cast<intArray>(m_data);
    }

    longArray Object::getLongs() {
        return static_cast<longArray>(m_data);
    }

    floatArray Object::getFloats() {
        return static_cast<floatArray>(m_data);
    }

    doubleArray Object::getDoubles() {
        return static_cast<doubleArray>(m_data);
    }

    refArray Object::getRefs() {
        return static_cast<refArray>(m_data);
    }

    java_int Object::getArrayLength() {
         return m_length;
    }

    Object* Object::getRefVar(string *name, string *descriptor) {
        Field *field = m_class->getField(name, descriptor, false);
        SlotArray *slotArray = (SlotArray*)m_data;
        return (Object *)slotArray->getRef(field->getSlotId());
    }

    Object* Object::setRefVar(string *name, string *descriptor, rt::Object *ref) {
        Field *field = m_class->getField(name, descriptor, false);
        SlotArray *slotArray = (SlotArray*)m_data;
        slotArray->setRef(field->getSlotId(), ref);
    }

    void *Object::getExtra() const {
        return m_extra;
    }

    void Object::setExtra(void *extra) {
        Object::m_extra = extra;
    }

    void *Object::getData() const {
        return m_data;
    }

    Object* Object::clone() {
        int length;
        void *data = this->cloneData(&length);
        return new Object(this->getClass(), data, length);
    }

    void* Object::cloneData(int *length) {
        string name = *getClass()->getName();
        *length = Object::m_length;
        void *data;
        if (name == "[Z") {
            data =  new java_bool[m_length];
            memcpy(m_data, data, sizeof(java_bool) * m_length);
        } else if (name == "[B") {
            data =  new java_byte[m_length];
            memcpy(m_data, data, sizeof(java_byte) * m_length);
        } else if (name == "[C") {
            data =  new java_char[m_length];
            memcpy(m_data, data, sizeof(java_char) * m_length);
        } else if (name == "[S") {
            data =  new java_short[m_length];
            memcpy(m_data, data, sizeof(java_short) * m_length);
        } else if (name == "[I") {
            data =  new java_int[m_length];
            memcpy(m_data, data, sizeof(java_int) * m_length);
        } else if (name == "[J") {
            data =  new java_long[m_length];
            memcpy(m_data, data, sizeof(java_long) * m_length);
        } else if (name == "[F") {
            data =  new java_float[m_length];
            memcpy(m_data, data, sizeof(java_float) * m_length);
        } else if (name == "[D") {
            data =  new java_double[m_length];
            memcpy(m_data, data, sizeof(java_double) * m_length);
        } else {
            data = new SlotArray(m_length);
        }
        return data;
    }


}