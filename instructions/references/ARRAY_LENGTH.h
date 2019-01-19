//
// Created by 郑邦国 on 2019/1/5.
//

#ifndef JVM_ARRAY_LENGTH_H
#define JVM_ARRAY_LENGTH_H


#include "../base/Instruction.h"

namespace rt {

    class ARRAY_LENGTH : public NoOperandsInstruction{
    public:
        void execute(Frame* frame);
    };

}


#endif //JVM_ARRAY_LENGTH_H
