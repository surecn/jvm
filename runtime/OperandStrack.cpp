//
// Created by 郑邦国 on 2018/11/22.
//

#include "OperandStrack.h"


namespace rt {

    OperandStrack *OperandStrack::newOperandStrack(int maxStack) {
        return new OperandStrack();
    }

    void OperandStrack::pushInt(int val) {
        //slot[size] = val;
        size++;
    }

    int OperandStrack::popInt() {
        size--;
        //return slot[size];
    }

}