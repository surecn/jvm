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

typedef char java_bool;
typedef char java_byte;
typedef unsigned short java_char;
typedef short java_short;
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

typedef java_byte* byteArray;
typedef java_char* charArray;
typedef java_short* shortArray;
typedef java_int* intArray;
typedef java_long* longArray;
typedef java_float* floatArray;
typedef java_double* doubleArray;
typedef java_ref* refArray;

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
