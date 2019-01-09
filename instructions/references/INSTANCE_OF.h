//
// Created by 郑邦国 on 2018/12/23.
//

#ifndef JVM_INSTANCEOF_H
#define JVM_INSTANCEOF_H


#include "../base/Instruction.h"

namespace rt {

    class INSTANCE_OF : public Index16Instruction{
    public:
        void execute(Frame* frame);
    };

}


#endif //JVM_INSTANCEOF_H
