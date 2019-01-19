//
// Created by 郑邦国 on 2018/12/30.
//

#ifndef JVM_METHODLOOKUP_H
#define JVM_METHODLOOKUP_H


#include "Method.h"

namespace rt {

    class MethodLookup {
    public:
        static Method* lookupMethodInClass(Class *cls, string *name, string *descriptor);
        static Method* lookupMethodInInterfaces(Class **cls, int interfaceCount, string *name, string *descriptor);
        static Method* lookupInterfaceMethod(rt::Class *interface, string *name, string *descriptor);
    };

}


#endif //JVM_METHODLOOKUP_H
