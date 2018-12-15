//
// Created by 郑邦国 on 2018/12/8.
//

#include "IFNull.h"

namespace rt {

    void IFNULL::execute(rt::Frame *frame) {
        java_ref ref = frame->getOperandStack()->popRef();
        if (ref == NULL) {
            branch(frame, _offset);
        }
    }

}
