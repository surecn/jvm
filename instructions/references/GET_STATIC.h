//
// Created by 郑邦国 on 2018/12/23.
//

#ifndef JVM_GET_STATIC_H
#define JVM_GET_STATIC_H


#include "../base/Instruction.h"

namespace rt {

    class GET_STATIC : public Index16Instruction {
    public:
        void execute(Frame* frame);
    };

}

#endif //JVM_GET_STATIC_H
