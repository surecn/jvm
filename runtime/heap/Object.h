//
// Created by 郑邦国 on 2018/12/22.
//

#ifndef JVM_OBJECT_H
#define JVM_OBJECT_H

#include "../../common/SlotArray.h"


namespace rt {
    extern class Class;
    class Object {
    private:
        Class *m_class;
        void *m_data;
        java_int m_length;
        //反射用的对象
        void *m_extra;
    public:
        Object(Class *cls);
        Object(Class *cls, void* data, int count);
        Class *getClass() const;
        bool isInstanceOf(Class *cls);
        SlotArray* getFields() const;

        byteArray getBytes();
        charArray getChars();
        shortArray getShorts();
        intArray getInts();
        longArray getLongs();
        floatArray getFloats();
        doubleArray getDoubles();
        refArray getRefs();
        java_int getArrayLength();

        void *getExtra() const;

        void setExtra(void *extra);

        void *getData() const;

        //reflection
        Object* getRefVar(string *name, string *descriptor);
        Object* setRefVar(string *name, string *descriptor, Object *ref);

        Object* clone();
        void* cloneData(int *length);

    };


}

#endif //JVM_OBJECT_H
