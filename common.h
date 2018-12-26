//
// Created by 郑邦国 on 2018/10/30.
//

#ifndef JVM_COMMON_H
#define JVM_COMMON_H



#include <iostream>
#include <string>
#include "common/StrUtils.h"
#include "common/BytesUtils.h"

using namespace std;

typedef float java_float;
typedef long java_int;
typedef long long java_long;
typedef double java_double;
typedef void* java_ref;

typedef unsigned char byte;

typedef unsigned char u1;    //uint8
typedef unsigned short u2;   //uint16
typedef unsigned int u4;     //uint32
typedef unsigned long u8;    //uint64

struct NameAndType {
    string *name;
    string *type;
};

static inline void logError(string s) {
    cout << "ERROR:" << s << endl;
}

static inline void logInfo(string s) {
    cout << "INFO:" << s << endl;
}

#define PATH_SEPARATOR "/"

#endif //JVM_COMMON_H
