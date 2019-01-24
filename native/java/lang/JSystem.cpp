//
// Created by 郑邦国 on 2019/1/12.
//

#include "JSystem.h"
#include "../../../runtime/heap/ArrayObject.h"
#include "../../../runtime/heap/Class.h"
#include "../../../runtime/heap/ArrayClass.h"
#include "../../../runtime/heap/StringPool.h"
#include "../../../instructions/base/MethodInvokeLogic.h"
#include <thread>


namespace native {

    void JSystem::init() {
        string clsName("java/lang/System");
        string methodName("arraycopy");
        string methodDescriptor("(Ljava/lang/Object;ILjava/lang/Object;II)V");
        Registry::registerNative(clsName, methodName, methodDescriptor, &JSystem::arraycopy);
        Registry::registerNative(clsName, "initProperties", "(Ljava/util/Properties;)Ljava/util/Properties;", &JSystem::initProperties);
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

    void JSystem::initProperties(rt::Frame *frame) {
//        rt::LocalVars *vars = frame->getLocalVars();
//        java_ref ref = vars->getRef(0);
//        rt::OperandStack *stack = frame->getOperandStack();
//        stack->pushRef(ref);
//
//        rt::Object* props = static_cast<rt::Object *>(ref);
//        string methodName("setProperty");
//        string descriptor("(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/Object;");
//        rt::Method* setPropMethod = props->getClass()->getInstanceMethod(methodName, descriptor);
//        rt::Thread* thread = frame->getThread();
//
//        string names[20][2] = {{"java.version", "1.8.0"},
//                               {"java.vendor", "jvm.go",},
//                               {"java.vendor.url", "https://github.com/zxh0/jvm.go"},
//                               {"java.home", "todo"},
//                               {"java.class.version", "52.0"},
//                               {"java.class.path", "todo"},
//                               {"java.awt.graphicsenv", "sun.awt.CGraphicsEnvironment"},
//                               {"os.name", "mac"},
//                               {"os.arch", "arch"},
//                               {"os.version", "",},
//                               {"file.separator", "/"},
//                               {"path.separator", ":"},
//                               {"line.separator", "\n"},
//                               {"user.name", ""},
//                               {"user.home", ""},
//                               {"user.dir", "."},
//                               {"user.country", "CN"},
//                               {"file.encoding", "UTF-8"},
//                               {"sun.stdout.encoding", "UTF-8"},
//                               {"sun.stderr.encoding", "UTF-8"}};
//        for (int i = 0; i < 20; ++i) {
//            rt::Object *jKey = rt::StringPool::getJString(frame->getMethod()->getClass()->getClassLoader(), names[i][0]);
//            rt::Object *jVal = rt::StringPool::getJString(frame->getMethod()->getClass()->getClassLoader(), names[i][1]);
//            rt::OperandStack *operandStack = new rt::OperandStack(3, names[i][0]);
//            operandStack->pushRef(props);
//            operandStack->pushRef(jKey);
//            operandStack->pushRef(jVal);
//            rt::Frame *shimframe = new ShimFrame();
//            thread->pushFrame(shimframe);
//            rt::MethodInvokeLogic::invokeMethod(shimframe, setPropMethod);
//            delete shimframe;
//            delete operandStack;
//        }

    }



}