
//
// Created by 郑邦国 on 2018/12/30.
//

#include "MethodInvokeLogic.h"
#include "../../runtime/Thread.h"
#include "../../runtime/heap/Class.h"

namespace rt {

    void MethodInvokeLogic::invokeMethod(rt::Frame *frame, rt::Method *method) {
        logError("invokeMethod  >>  " + *method->getName() + "  >>" + *method->getClass()->getName());
        Thread *thread = frame->getThread();
        Frame *newFrame = thread->newFrame(method);
        thread->pushFrame(newFrame);
        int argSlotCount = method->getArgSlotCount();
        if (argSlotCount > 0) {
            for (int i = argSlotCount - 1; i >= 0; --i) {
                java_int slot = frame->getOperandStack()->popSlot();
                newFrame->getLocalVars()->setSlot(i, slot);
            }
        }
//        // hack!
//        if (method->isNative()) {
//            if (*method->getName() == "registerNatives") {
//                thread->popFrame();
//            } else {
//                cout << "native method:" << method->getName() << "  descriptor:" << method->getDescriptor() << endl;
//            }
//        }
    }

}