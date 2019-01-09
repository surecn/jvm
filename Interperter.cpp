//
// Created by 郑邦国 on 2018/12/8.
//

#include "Interperter.h"
#include "classfile/attribute/CodeAttribute.h"
#include "runtime/Thread.h"
#include "instructions/base/BytecodeReader.h"
#include "instructions/base/Instruction.h"
#include "instructions/Factory.h"

static void loop(rt::Thread *thread, byte *bytecode) {
    rt::Frame* frame = thread->popFrame();
    rt::BytecodeReader reader;
    java_int pc;
    int opCode;
    while (true) {
        pc = frame->getNextPc();
        thread->setPC(pc);
        //decode
        reader.reset(bytecode, pc);
        opCode = reader.readU1();
        rt::Instruction* instruction = rt::Factory::newInstruction(opCode);
        instruction->fetchOperand(&reader);
        frame->setNextPc(reader.PC());
        //execute
        //cout << "pc:" << pc << hex << "=" << opcode << endl;
        //printf("pc:%2d inst:%T %v\n", pc, instruction, instruction);
        instruction->execute(frame);
        rt::Factory::releaseInstruction(instruction, opCode);
    }
}


void Interperter::interpret(rt::Method *method) {
    rt::Thread* thread = rt::Thread::newThread();
    rt::Frame *frame = thread->newFrame(method);
    thread->pushFrame(frame);
    loop(thread, method->getCode());
}


