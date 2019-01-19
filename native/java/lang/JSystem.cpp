//
// Created by 郑邦国 on 2019/1/12.
//

#include "JSystem.h"
#include "../../../runtime/heap/ArrayObject.h"
#include "../../../runtime/heap/Class.h"
#include "../../../runtime/heap/ArrayClass.h"
#include <thread>


namespace native {

    void JSystem::init() {
        string clsName("java/lang/System");
        string methodName("arraycopy");
        string methodDescriptor("(Ljava/lang/Object;ILjava/lang/Object;II)V");
        Registry::registerNative(clsName, methodName, methodDescriptor, &JSystem::arraycopy);
    }

    bool checkArrayCopy(rt::Object *src, rt::Object *dest) {
        rt::ArrayClass *srcClass = (rt::ArrayClass *)src->getClass();
        rt::ArrayClass *destClass = (rt::ArrayClass *)dest->getClass();

        if (!srcClass->isArray() || !destClass->isArray()) {
            return false;
        }
        if (srcClass->getComponentClass()->isPrimitive() ||
                destClass->getComponentClass()->isPrimitive()) {
            return srcClass == destClass;
        }
        return true;
    }

    void JSystem::arraycopy(rt::Frame *frame) {
        rt::LocalVars *localVars = frame->getLocalVars();
        java_ref src = localVars->getRef(0);
        java_int srcPos = localVars->getInt(1);
        java_ref dest = localVars->getRef(2);
        java_int destPos = localVars->getInt(3);
        java_int length = localVars->getInt(4);
        if (src == NULL || dest == NULL) {
            logError("java.lang.NullPointerException");
        }

        if (!checkArrayCopy((rt::Object*)src, (rt::Object*)dest)) {
            logError("java.lang.ArrayStoreException");
        }

        if (srcPos < 0 || destPos < 0 || length < 0) {
            logError("java.lang.IndexOutOfBoundsException");
        }

        rt::ArrayObject::ArrayCopy((rt::Object*)src, (rt::Object*)dest, srcPos, destPos, length);
    }

}