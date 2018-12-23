//
// Created by 郑邦国 on 2018/12/23.
//

#ifndef JVM_PUT_FIELD_H
#define JVM_PUT_FIELD_H


#include "../base/Instruction.h"

namespace rt {

    class PUT_FIELD : Index16Instruction {
    public:
        void execute(Frame* frame);
    };


}


#endif //JVM_PUT_FIELD_H
