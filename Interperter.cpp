//
// Created by 郑邦国 on 2018/12/8.
//


#include "Interperter.h"
#include "classfile/attribute/CodeAttribute.h"
#include "runtime/Thread.h"
#include "instructions/base/BytecodeReader.h"
#include "instructions/Factory.h"
#include "runtime/heap/Class.h"
#include <iomanip>
#include "runtime/heap/ClassLoader.h"
#include "runtime/heap/ArrayClass.h"
#include "runtime/heap/StringPool.h"

void Interperter::catchError(rt::Thread *thread) {

}

void Interperter::logInstruction(rt::Frame *frame, rt::Instruction *instruction) {
    rt::Method *method = frame->getMethod();
    rt::Class *cls = method->getClass();
    string *className = cls->getName();
    cout << setw(4) << frame->getNextPc() << " " << *className << "." << *method->getName() << *method->getDescriptor() << endl;
}

void Interperter::loop(rt::Thread *thread, bool logInst) {
    rt::BytecodeReader reader;
    rt::Instruction* instruction;
    java_int pc;
    int opCode;
    while (true) {
        rt::Frame *frame = thread->currentFrame();
        pc = frame->getNextPc();
        thread->setPC(pc);
        //decode
        reader.reset(frame->getMethod()->getCode(), pc);
        opCode = reader.readU1();
        instruction = rt::Factory::newInstruction(opCode);
        instruction->fetchOperand(&reader);
        frame->setNextPc(reader.PC());
//        if (logInst) {
//            logInstruction(frame, instruction);
//        }
        //execute
        cout << "pc:" << pc << hex << "=" << opCode << endl;
        //printf("pc:%2d inst:%T %v\n", pc, instruction, instruction);
        instruction->execute(frame);
        if (thread->isStackEmpty()) {
            break;
        }
        rt::Factory::releaseInstruction(instruction, opCode);
        instruction = NULL;
    }
}


void Interperter::interpret(rt::Thread *thread, bool logInst) {
    catchError(thread);
    loop(thread, logInst);
}


