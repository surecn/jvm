//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_IFNULL_H
#define JVM_IFNULL_H


#include "../base/Instruction.h"

namespace rt {

    class IFNULL : public BranchInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_IFNULL_H
