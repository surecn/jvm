//
// Created by 郑邦国 on 2018/12/23.
//

#ifndef JVM_NEW_H
#define JVM_NEW_H


#include "../base/Instruction.h"

namespace rt {

    class NEW : public Index16Instruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_NEW_H
