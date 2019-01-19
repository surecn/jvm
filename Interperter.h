//
// Created by 郑邦国 on 2018/12/8.
//

#ifndef JVM_INTERPERTER_H
#define JVM_INTERPERTER_H


#include "classfile/Constants.h"
#include "runtime/Frame.h"
#include "instructions/base/Instruction.h"

class Interperter {
public:
    static void catchError(rt::Thread *thread);
    static void logInstruction(rt::Frame *frame, rt::Instruction *instruction);
    static void loop(rt::Thread *thread, bool logInst);
    static void interpret(rt::Method *method, bool logInst, string args[]);
};


#endif //JVM_INTERPERTER_H
