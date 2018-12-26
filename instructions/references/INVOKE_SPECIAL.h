//
// Created by 郑邦国 on 2018/12/26.
//

#ifndef JVM_INVOKE_SPECIAL_H
#define JVM_INVOKE_SPECIAL_H


#include "../base/Instruction.h"

namespace rt {

    class INVOKE_SPECIAL : public Index16Instruction {
    public:
        void execute(Frame* frame);
    };

}


#endif //JVM_INVOKE_SPECIAL_H
