//
// Created by 郑邦国 on 2019/1/15.
//

#ifndef JVM_JSTRING_H
#define JVM_JSTRING_H


#include "../../../runtime/Frame.h"
#include <map>

namespace native {

    class JString {
    private:
        static map<string, rt::Object*> s_internedStrings;
        static rt::Object* internString(rt::Object *jStr);
    public:
        static void init();
        static void intern(rt::Frame* frame);
    };

}


#endif //JVM_JSTRING_H
