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

<<<<<<< HEAD
<<<<<<< HEAD
typedef char byte;
=======
=======
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
typedef float java_float;
typedef long java_int;
typedef long long java_long;
typedef double java_double;
typedef void* java_ref;

typedef unsigned char byte;
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e

typedef unsigned char u1;    //uint8
typedef unsigned short u2;   //uint16
typedef unsigned int u4;     //uint32
typedef unsigned long u8;    //uint64

<<<<<<< HEAD
<<<<<<< HEAD
#define PATH_SEPARATOR "/"

#endif //JVM_COMMON_H
=======
=======
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
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
<<<<<<< HEAD
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
=======
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
