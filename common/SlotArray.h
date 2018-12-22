//
// Created by 郑邦国 on 2018/12/22.
//

#ifndef JVM_SLOTARRAY_H
#define JVM_SLOTARRAY_H


#include "../common.h"

class SlotArray {
private:
    java_int *m_slots;
public:
    SlotArray(u4 size);

    void setInt(int index, java_int val);
    java_int getInt(int index);

    void setLong(int index, java_long val);
    java_long getLong(int index);

    void setFloat(int index, java_float val);
    java_float getFloat(int index);

    void setDouble(int index, java_double val);
    java_double getDouble(int index);

    void setRef(int index, java_ref val);
    java_ref getRef(int index);
};


#endif //JVM_SLOTARRAY_H
