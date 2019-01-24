//
// Created by 郑邦国 on 2019/1/21.
//

#ifndef JVM_JTHROWABLE_H
#define JVM_JTHROWABLE_H

#include "../../../common.h"
#include "../../../runtime/Frame.h"

namespace native {

    class StackTraceElement {
    private:
        string m_fileName;
        string m_className;
        string m_methodName;
        int m_lineNumber;
        static int distanceToObject(rt::Class *cls);
        static StackTraceElement* createStackTraceElement(rt::Frame *frame);
        static StackTraceElement** createStackTraceElements(rt::Object *obj, rt::Thread *thread);
    public:
        static void init();
        static void fillInStackTrace(rt::Frame *frame);
    };

}


#endif //JVM_JTHROWABLE_H
