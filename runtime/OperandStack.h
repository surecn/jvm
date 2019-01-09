//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_OPERANDSTRACK_H
#define JVM_OPERANDSTRACK_H


#include "../common.h"
#include "../common/SlotArray.h"

namespace rt {
    class OperandStack {
    private:
        int m_size;
        java_int *m_slots;//win64位除外
    public:
        OperandStack(java_int val);
        void pushInt(java_int val); //java int
        long popInt();
        void pushLong(java_long val); //java long
        java_long popLong();
        void pushFloat(java_float val);
        java_float popFloat();
        void pushDouble(java_double val);
        java_double popDouble();
        void pushRef(java_ref ptr);
        java_ref popRef();
        void pushSlot(java_int slot);
        java_int popSlot();
    };
}


#endif //JVM_OPERANDSTRACK_H
