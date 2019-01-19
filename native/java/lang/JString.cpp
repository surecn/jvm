//
// Created by 郑邦国 on 2019/1/15.
//

#include "JString.h"
#include "../../Registry.h"
#include "../../../runtime/heap/StringPool.h"

namespace native {

    map<string, rt::Object*> JString::s_internedStrings;

    void JString::init() {
        string className("java/lang/String");
        string methodName("intern");
        string methodDescriptor("()Ljava/lang/String;");
        Registry::registerNative(className, methodName, methodDescriptor, &(JString::intern));
    }

    rt::Object* JString::internString(rt::Object *jStr) {
        string str = rt::StringPool::getCString(jStr);
        rt::Object *jO = s_internedStrings[str];
        if (jO != NULL) {
            return jO;
        }
        s_internedStrings[str] = jStr;
        return jStr;
    }

    void JString::intern(rt::Frame *frame) {
        rt::Object *obj = frame->getLocalVars()->getThis();
        rt::Object *interned = internString(obj);
        frame->getOperandStack()->pushRef(interned);
    }

}