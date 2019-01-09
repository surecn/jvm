//
// Created by 郑邦国 on 2018/12/23.
//

#ifndef JVM_CHECK_CAST_H
#define JVM_CHECK_CAST_H


#include "../base/Instruction.h"

namespace rt {

    class CHECK_CAST : public Index16Instruction {
    public:
        void execute(Frame* frame);
    };

}


#endif //JVM_CHECK_CAST_H
