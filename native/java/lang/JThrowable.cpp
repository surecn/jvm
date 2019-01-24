//
// Created by 郑邦国 on 2019/1/21.
//

#include "JThrowable.h"
#include "../../../runtime/heap/Class.h"
#include "../../Registry.h"

namespace native {

    void StackTraceElement::init() {
        string clsName("java/lang/Throwable");
        string methodName("fillInStackTrace");
        string methodDescriptor("(I)Ljava/lang/Throwable;");
        Registry::registerNative(clsName, methodName, methodDescriptor, &StackTraceElement::fillInStackTrace);
    }

    int StackTraceElement::distanceToObject(rt::Class *cls) {
        int distance = 0;
        for (rt::Class *c = cls->getSuperClass(); c != NULL; c = c->getSuperClass()) {
            distance++;
        }
        return distance;
    }

    StackTraceElement* StackTraceElement::createStackTraceElement(rt::Frame *frame) {
        rt::Method *method = frame->getMethod();
        rt::Class *cls = method->getClass();
        StackTraceElement *stackTraceElement = new StackTraceElement();
        stackTraceElement->m_fileName = cls->getSourceFile();
        stackTraceElement->m_className = cls->getJavaName();
        stackTraceElement->m_methodName = *cls->getName();
        stackTraceElement->m_lineNumber = method->getLineNumber(frame->getNextPc() - 1);
    }

    StackTraceElement** StackTraceElement::createStackTraceElements(rt::Object *obj, rt::Thread *thread) {
        int skip = distanceToObject(obj->getClass()) + 2;
        rt::Stack *stack = thread->getFrames();
        StackTraceElement **stes = new StackTraceElement*[stack->getSize() - skip];
        rt::Frame *frame = stack->top();
        for (int i = stack->getSize() - skip; i > 0; --i) {
            stes[i] = createStackTraceElement(frame);
            frame = frame->m_lower;
        }
        return stes;
    }

    void StackTraceElement::fillInStackTrace(rt::Frame *frame) {
        rt::Object *obj = frame->getLocalVars()->getThis();
        frame->getOperandStack()->pushRef(obj);
        StackTraceElement **stes = createStackTraceElements(obj, frame->getThread());
        obj->setExtra(stes);
    }

}