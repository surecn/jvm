//
// Created by 郑邦国 on 2018/12/6.
//

#include "Goto.h"

namespace rt {

    void GOTO::execute(rt::Frame *frame) {
        branch(frame, m_offset);
    }

}