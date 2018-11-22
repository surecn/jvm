//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_FRAME_H
#define JVM_FRAME_H

#include "../common.h"

namespace rt {
    class Frame {
    private:
        Frame* lower;
        LocalVars localVars;
        OperandStrack* operandStrack;
        Frame();
    public:
        static Frame* newFrame(int maxLocal, int maxStrack);
    };

}

#endif //JVM_FRAME_H
