//
// Created by 郑邦国 on 2019/1/13.
//

#include "JFloat.h"
#include "../../Registry.h"

namespace native {

    void JFloat::init() {
        string clsName("java/lang/Float");
        string methodName("floatToRawIntBits");
        string methodDescriptor("(F)I");
        Registry::registerNative(clsName, methodName, methodDescriptor, &(JFloat::floatToRawIntBits));
    }

    void JFloat::floatToRawIntBits(rt::Frame *frame) {
        float value = frame->getLocalVars()->getFloat(0);
        u1 ch[SIZE_INT];
        BytesUtils::floatToBytes(value, ch);
        frame->getOperandStack()->pushInt(BytesUtils::bytesToInt(ch));
    }

}