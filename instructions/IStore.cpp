//
// Created by 郑邦国 on 2018/11/24.
//

#include "IStore.h"

namespace rt {

    IStore::IStore(int _index) : index(_index) {}

    void IStore::execute(rt::Frame *frame) {
        long val = frame->getOperandStack()->popLong();
        frame->getLocalVars()->setLong(index, val);
    }



}
