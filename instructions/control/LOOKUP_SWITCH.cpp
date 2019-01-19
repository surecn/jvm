//
// Created by 郑邦国 on 2018/12/7.
//

#include "LOOKUP_SWITCH.h"

namespace rt {

    void LOOKUP_SWITCH::fetchOperand(rt::BytecodeReader *reader) {
        reader->skipPadding();
        defaultOffset = reader->readU4();
        npairs = reader->readU4();
        matchOffsets = reader->readU4s(npairs * 2);
    }

    void LOOKUP_SWITCH::execute(rt::Frame *frame) {
        java_int key = frame->getOperandStack()->popInt();
        u4 len = npairs * 2;
        for (int i = 0; i < len; i+=2) {
            if (matchOffsets[i] == key) {
                m_offset = matchOffsets[i + 1];
                branch(frame, m_offset);
                return;
            }
        }
        branch(frame, defaultOffset);
    }

}