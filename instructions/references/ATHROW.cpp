//
// Created by 郑邦国 on 2019/1/21.
//

#include "ATHROW.h"
#include "../../runtime/Thread.h"
#include "../../runtime/heap/StringPool.h"

namespace rt {

    bool findAndGotoExceptionHandler(Thread *thread, Object *ex) {
        while (true) {
            Frame *frame = thread->currentFrame();
            int pc = frame->getNextPc() - 1;
            int handlerPC = frame->getMethod()->findExceptionHandler(ex->getClass(), pc);
            if (handlerPC > 0) {
                OperandStack *stack = frame->getOperandStack();
                stack->clear();
                stack->pushRef(ex);
                frame->setNextPc(handlerPC);
                return true;
            }
            thread->popFrame();
            if (thread->isStackEmpty()) {
                break;
            }
        }
        return false;
    }

    bool handleUncaughtException(Thread *thread, Object *ex) {
        thread->clearStack();
        string name("detailMessage");
        string descriptor("Ljava/lang/String;");
        Object *jMsg = ex->getRefVar(name, descriptor);
        string cstr = StringPool::getCString(jMsg);
        cout << ex->getClass()->getJavaName() << ":" << cstr << endl;
        ex->getExtra();

    }

    void ATHROW::execute(rt::Frame *frame) {
        Object *ex = (Object*)frame->getOperandStack()->popRef();
        if (ex != NULL) {
            logError("java.lang.NullPointerException");
        }
        Thread *thread = frame->getThread();
        if (!findAndGotoExceptionHandler(thread, ex)) {
            handleUncaughtException(thread, ex);
        }
    }


}