//
// Created by 郑邦国 on 2018/12/30.
//

#include "RETURN.h"
#include "../../runtime/Thread.h"

namespace rt {

    void RETURN::execute(rt::Frame *frame) {
        frame->getThread()->popFrame();
    }

    void ARETURN::execute(rt::Frame *frame) {
        Thread *thread = frame->getThread();
        Frame *currentFrame = thread->popFrame();
        Frame *invokeFrame = thread->topFrame();
        java_ref val = currentFrame->getOperandStack()->popRef();
        invokeFrame->getOperandStack()->pushRef(val);
    }

    void IRETURN::execute(rt::Frame *frame) {
        Thread *thread = frame->getThread();
        Frame *currentFrame = thread->popFrame();
        Frame *invokeFrame = thread->topFrame();
        java_int val = currentFrame->getOperandStack()->popInt();
        invokeFrame->getOperandStack()->pushInt(val);
    }

    void LRETURN::execute(rt::Frame *frame) {
        Thread *thread = frame->getThread();
        Frame *currentFrame = thread->popFrame();
        Frame *invokeFrame = thread->topFrame();
        java_long val = currentFrame->getOperandStack()->popLong();
        invokeFrame->getOperandStack()->pushLong(val);
    }

    void FRETURN::execute(rt::Frame *frame) {
        Thread *thread = frame->getThread();
        Frame *currentFrame = thread->popFrame();
        Frame *invokeFrame = thread->topFrame();
        java_float val = currentFrame->getOperandStack()->popFloat();
        invokeFrame->getOperandStack()->pushFloat(val);
    }

    void DRETURN::execute(rt::Frame *frame) {
        Thread *thread = frame->getThread();
        Frame *currentFrame = thread->popFrame();
        Frame *invokeFrame = thread->topFrame();
        java_double val = currentFrame->getOperandStack()->popDouble();
        invokeFrame->getOperandStack()->pushDouble(val);
    }



}