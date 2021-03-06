//
// Created by 郑邦国 on 2018/12/23.
//

#ifndef JVM_PUTSTATIC_H
#define JVM_PUTSTATIC_H


#include "../base/Instruction.h"

namespace rt {

    class PUT_STATIC : public Index16Instruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_PUTSTATIC_H
