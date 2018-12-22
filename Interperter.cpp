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
    int opcode;
    while (true) {
        pc = frame->getNextPc();
        thread->setPC(pc);
        //decode
        reader.reset(bytecode, pc);
        opcode = reader.readU1();
        rt::Instruction *instruction = rt::Factory::newInstruction(opcode);
        instruction->fetchOperand(&reader);
        frame->setNextPc(reader.PC());

        //execute
        printf("pc:%2d inst:%T %v\n", pc, instruction, instruction);
        instruction->execute(frame);
    }
}


void Interperter::interpret(cf::MemberInfo *memberInfo) {
    cf::CodeAttribute* attribute = memberInfo->getCodeAttribute();
    u2 maxLocals = attribute->getMaxLocals();
    u2 maxStack = attribute->getMaxStack();
    u1* code = attribute->getCode();
    u4 codeLength = attribute->getCodeLength();
    rt::Thread* thread = rt::Thread::newThread();
    rt::Frame* frame = thread->newFrame(maxLocals, maxStack);
    thread->pushFrame(frame);
    loop(thread, code);
}


