//
// Created by 郑邦国 on 2019/1/24.
//

#include "JThread.h"
#include "../../Registry.h"
#include "../../../runtime/heap/ClassLoader.h"
#include "../../../runtime/heap/Class.h"
#include "../../../runtime/heap/Object.h"


namespace native {

    void JThread::init() {
        string clsName("java/lang/Thread");
        Registry::registerNative(clsName, "currentThread", "()Ljava/lang/Thread;", &JThread::currentThread);
    }

    void JThread::currentThread(rt::Frame *frame) {
        rt::ClassLoader *classLoader = frame->getMethod()->getClass()->getClassLoader();
        string threadName("java/lang/Thread");
        rt::Class *threadClass = classLoader->loadClass(&threadName);
        rt::Object *jThread = new rt::Object(threadClass);

        string threadGroupName("java/lang/ThreadGroup");
        rt::Class *threadGroupClass = classLoader->loadClass(&threadGroupName);
        rt::Object *jGroup = new rt::Object(threadGroupClass);

        string groupName("group");
        string groupDescriptor("Ljava/lang/ThreadGroup;");
        jThread->setRefVar(groupName, groupDescriptor, jGroup);
        string priorityName("priority");
        string priorityDescriptor("I");
        jThread->setIntVar(priorityName, priorityDescriptor, 1);

        frame->getOperandStack()->pushRef(jThread);
    }

}