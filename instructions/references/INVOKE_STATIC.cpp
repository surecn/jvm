//
// Created by 郑邦国 on 2018/12/30.
//

#include "INVOKE_STATIC.h"
#include "../../runtime/heap/Class.h"
#include "../../runtime/heap/MethodRef.h"
#include "../base/MethodInvokeLogic.h"
#include "../../runtime/heap/ConstantPool.h"

namespace rt {

    void INVOKE_STATIC::execute(rt::Frame *frame) {
        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
        MethodRef *mehtodRef = cp->getMethodRef(m_index);
        Method *method = mehtodRef->resolvedMethod();
        if (!method->isStatic()) {
            logError("java.lang.IncompatibleClassChangeError");
        }

        Class *cls = method->getClass();
        if (!cls->isInitStarted()) {
            frame->revertNextPC();
            cls->initClass(frame->getThread());
            return;
        }

        MethodInvokeLogic::invokeMethod(frame, method);
    }

}