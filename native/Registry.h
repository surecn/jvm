//
// Created by 郑邦国 on 2019/1/9.
//

#ifndef JVM_REGISTRY_H
#define JVM_REGISTRY_H


#include "../runtime/Frame.h"
#include <map>

namespace native {
    typedef void (*Fun)(rt::Frame*);
    class Registry {
    private:
        static map<string, void(*)(rt::Frame *)> *s_registry;
        static Fun s_emptyNativeMethod;
        static int initData;
        static int init();
    public:
        static void registerNative(string className, string methodName, string descriptor, Fun method);
        static Fun findNativeMethod(string *className, string *methodName, string *descriptor);
        static void emptyNativeMethod(rt::Frame* frame);
    };

}


#endif //JVM_REGISTRY_H
