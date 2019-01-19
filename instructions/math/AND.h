//
// Created by 郑邦国 on 2018/11/30.
//

#ifndef JVM_AND_H
#define JVM_AND_H


#include "../base/Instruction.h"

namespace rt {

    class LAND : public NoOperandsInstruction {
        void execute(rt::Frame* frame);
    };

    class IAND : public NoOperandsInstruction {
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_AND_H
