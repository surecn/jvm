//
// Created by 郑邦国 on 2018/12/23.
//

#ifndef JVM_GET_FIELD_H
#define JVM_GET_FIELD_H


#include "../base/Instruction.h"

namespace rt {

    class GET_FIELD : public Index16Instruction {
    public:
        void execute(Frame* frame);
    };


}


#endif //JVM_GET_FIELD_H
