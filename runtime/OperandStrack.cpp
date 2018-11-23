//
// Created by 郑邦国 on 2018/11/22.
//

#include "OperandStrack.h"
#include "../common.h"


namespace rt {

    OperandStrack *OperandStrack::newOperandStrack(int maxStack) {
        return new OperandStrack();
    }

    void OperandStrack::pushInt(int val) {
        slot[size] = val;
        size++;
    }

    int OperandStrack::popInt() {
        size--;
        return slot[size];
    }

    void OperandStrack::pushFloat(float val) {
        u1 data[4];
        DataUtils::floatToBytes(val, data);
        slot[size] = DataUtils::bytesToInt(data, 4);
    }


}