//// Created by 郑邦国 on 2018/12/6.//#include "TableSwitch.h"namespace rt {    void TABLE_SWITCH::fetchOperand(rt::BytecodeReader *reader) {        reader->skipPadding();        defaultOffset = reader->readU4();        low = reader->readU4();        high = reader->readU4();        u4 jumpOffsetsCount = high - low + 1;        jumpOffsets = reader->readU4s(jumpOffsetsCount);    }    void TABLE_SWITCH::execute(rt::Frame *frame) {        java_int index = frame->getOperandStack()->popInt();        u4 offset;        if (index >= low && index <= high) {            offset = jumpOffsets[index - low];        } else {            offset = jumpOffsets[defaultOffset];        }        branch(frame, offset);    }}