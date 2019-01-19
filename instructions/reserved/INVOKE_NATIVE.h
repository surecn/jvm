//
// Created by 郑邦国 on 2019/1/9.
//

#ifndef JVM_INVOKE_NATIVE_H
#define JVM_INVOKE_NATIVE_H


#include "../base/Instruction.h"

namespace rt {

    class INVOKE_NATIVE : public NoOperandsInstruction {
    public:
        void execute(Frame* frame);
    };

}


#endif //JVM_INVOKE_NATIVE_H
