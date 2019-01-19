//
// Created by 郑邦国 on 2019/1/4.
//

#ifndef JVM_ANEW_ARRAY_H
#define JVM_ANEW_ARRAY_H

#include "../base/Instruction.h"

namespace rt {

    class ANEW_ARRAY : public Index16Instruction{
    public:
        void execute(Frame* frame);
    };

}


#endif //JVM_ANEW_ARRAY_H
