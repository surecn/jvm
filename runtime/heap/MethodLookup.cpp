//
// Created by 郑邦国 on 2018/12/30.
//

#include "MethodLookup.h"
#include "Class.h"

namespace rt {

    Method* MethodLookup::lookupMethodInClass(rt::Class *cls, string *name, string *descriptor) {
        for (Class *c = cls; c != NULL ; c = c->getSuperClass()) {
            Method **methods = c->getMethods();
            if (methods != NULL) {
                for (int i = 0, len = c->getMethodCount(); i < len; ++i) {
                    Method *method = methods[i];
                    if (*method->getName() == *name && *method->getDescriptor() == *descriptor) {
                        return method;
                    }
                }
            }
        }
        return NULL;
    }

    Method* MethodLookup::lookupMethodInInterfaces(rt::Class **cls, int interfaceCount, string *name, string *descriptor) {
        Method *method = NULL;
        for (int i = 0; i < interfaceCount; ++i) {
            Class *interface = cls[i];
            Method **methods = interface->getMethods();
            for (int j = 0, len = interface->getMethodCount(); j < len; ++j) {
                method = methods[j];
                if (*method->getName() == *name && *method->getDescriptor() == *descriptor) {
                    return method;
                }
            }
            method = lookupMethodInInterfaces(interface->getInterfaces(), interface->getInterfaceCount(), name, descriptor);
            if (method != NULL) {
                return method;
            }
        }
        return NULL;
    }

    Method* MethodLookup::lookupInterfaceMethod(rt::Class *interface, string *name, string *descriptor) {
        Method **methods = interface->getMethods();
        for (int i = 0, len = interface->getMethodCount(); i < len; ++i) {
            Method *method = methods[i];
            if (*method->getName() == *name && *method->getDescriptor() == *descriptor) {
                return method;
            }
        }
        lookupMethodInInterfaces(interface->getInterfaces(), interface->getInterfaceCount(), name, descriptor);
    }

}