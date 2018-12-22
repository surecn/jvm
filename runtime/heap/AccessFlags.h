//
// Created by 郑邦国 on 2018/12/17.
//

#ifndef JVM_ACCESSFLAGS_H
#define JVM_ACCESSFLAGS_H

#endif //JVM_ACCESSFLAGS_H

namespace rt {
    const int ACC_PUBLIC                  = 0x0001; // class field method
    const int ACC_PRIVATE                 = 0x0002; //       field method
    const int ACC_PROTECTED               = 0x0004; //       field method
    const int ACC_STATIC                  = 0x0008; //       field method
    const int ACC_FINAL                   = 0x0010; // class field method
    const int ACC_SUPER                   = 0x0020; // class
    const int ACC_SYNCHRONIZED            = 0x0020; //             method
    const int ACC_VOLATILE                = 0x0040; //       field
    const int ACC_BRIDGE                  = 0x0040; //             method
    const int ACC_TRANSIENT               = 0x0080; //       field
    const int ACC_VARARGS                 = 0x0080; //             method
    const int ACC_NATIVE                  = 0x0100; //             method
    const int ACC_INTERFACE               = 0x0200; // class
    const int ACC_ABSTRACT                = 0x0400; // class       method
    const int ACC_STRICT                  = 0x0800; //             method
    const int ACC_SYNTHETIC               = 0x1000; // class field method
    const int ACC_ANNOTATION              = 0x2000; // class
    const int ACC_ENUM                    = 0x4000; // class field
}