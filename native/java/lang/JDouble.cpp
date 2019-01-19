//
// Created by 郑邦国 on 2019/1/14.
//

#include "JDouble.h"
#include "../../Registry.h"

namespace native {

    void JDouble::init() {
        string clsName("java/lang/Double");
        Registry::registerNative(clsName, "doubleToRawLongBits", "(D)J", &(JDouble::doubleToRawLongBits));
        Registry::registerNative(clsName, "longBitsToDouble", "(J)D", &(JDouble::longBitsToDouble));
    }

    void JDouble::doubleToRawLongBits(rt::Frame *frame) {
        float value = frame->getLocalVars()->getFloat(0);
        u1 ch[SIZE_INT * 2];
        BytesUtils::doubleToBytes(value, ch);
        frame->getOperandStack()->pushInt(BytesUtils::bytesToLong(ch));
    }

    void JDouble::longBitsToDouble(rt::Frame *frame) {
        long bits = frame->getLocalVars()->getLong(0);
        u1 ch[SIZE_INT * 2];
        BytesUtils::longToBytes(bits, ch);
        double value = BytesUtils::bytesToDouble(ch);
    }


}
