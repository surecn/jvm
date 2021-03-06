//
// Created by 郑邦国 on 2018/12/30.
//

#ifndef JVM_INVOKE_STATIC_H
#define JVM_INVOKE_STATIC_H


#include "../base/Instruction.h"

namespace rt {

    class INVOKE_STATIC : public Index16Instruction {
    public:
        void execute(Frame* frame);
    };

}


#endif //JVM_INVOKE_STATIC_H
