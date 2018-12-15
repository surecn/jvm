//
// Created by 郑邦国 on 2018/11/30.
//

#ifndef JVM_IINC_H
#define JVM_IINC_H


#include "../base/Instruction.h"

namespace rt {

    class IINC : public Instruction {
    private:
        u4 _index;
        java_int constant;
    public:
        void setIndex(u4 index);
        void setConstant(java_int val);
        void execute(rt::Frame* frame);
        void fetchOperand(BytecodeReader* reader);
    };



}


#endif //JVM_IINC_H
