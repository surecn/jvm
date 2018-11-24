//
// Created by 郑邦国 on 2018/11/24.
//

#ifndef JVM_ISTORE_H
#define JVM_ISTORE_H


#include "Instruction.h"

namespace rt {

    class IStore : public Index8Instruction {
    private:
        int index;
    public:
        IStore(int index);
        void execute(rt::Frame* frame);
    };
}


#endif //JVM_ISTORE_H
