//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_FRAME_H
#define JVM_FRAME_H

#include "../common.h"
#include "OperandStrack.h"
#include "LocalVars.h"

namespace rt {
    class Frame {
    private:
        LocalVars* localVars;
        OperandStrack* operandStrack;
    public:
        Frame* lower;
        Frame();
        OperandStrack* getOperandStrack();
        LocalVars* getLocalVars();
        static Frame* newFrame(int maxLocal, int maxStrack);
    };

}

#endif //JVM_FRAME_H
