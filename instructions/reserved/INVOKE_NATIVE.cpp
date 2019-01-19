//
// Created by 郑邦国 on 2019/1/9.
//

#include "INVOKE_NATIVE.h"
#include "../../runtime/heap/Class.h"
#include "../../native/Registry.h"

namespace rt {

    void INVOKE_NATIVE::execute(rt::Frame *frame) {
        Method* method = frame->getMethod();
        string *className = method->getClass()->getName();
        string *methodName = method->getName();
        cout << "INVOKE_NATIVE " << *methodName << endl;
        string *methodDescriptor = method->getDescriptor();
        native::Fun nativeMathod = native::Registry::findNativeMethod(className, methodName, methodDescriptor);
        if (nativeMathod == NULL) {
            string methodInfo = *className + "." + *methodName + *methodDescriptor;
            logError("java.lang.UnsatisfiedLinkError: " + methodInfo);
        }
        nativeMathod(frame);
    }

}