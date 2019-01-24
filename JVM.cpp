//
// Created by 郑邦国 on 2019/1/22.
//

#include "JVM.h"
#include "Interperter.h"
#include "runtime/heap/StringPool.h"
#include "runtime/heap/ArrayClass.h"

JVM::JVM(MainParamater *cmd) {
    m_cmd = cmd;
    m_cp = new cp::ClassPath(cmd->m_xjreOption, cmd->m_cpOption);
    m_classLoader = new rt::ClassLoader(m_cp, cmd->m_verboseClassFlag);
    m_mainThread = rt::Thread::newThread();
}

JVM::~JVM() {
    delete m_cp;
    delete m_classLoader;
    delete m_classLoader;
    delete m_mainThread;
}

void JVM::start() {
    initVM();
    execMain();
}

void JVM::initVM() {
    string clsVMName("sun/misc/VM");
    rt::Class *clsVM = m_classLoader->loadClass(&clsVMName);
    clsVM->initClass(m_mainThread);
    Interperter::interpret(m_mainThread, m_cmd->m_verboseInstFlag);
}

void JVM::execMain() {
    string className = m_cmd->m_className;
    StrUtils::replace(className, ".", "/");

    rt::Class *mainClass = m_classLoader->loadClass(&className);
    rt::Method *mainMethod = mainClass->getMainMethod();
    if (mainMethod == NULL) {
        return;
    }
    rt::Object *argsArr = createArgsArray();
    rt::Frame *frame = m_mainThread->newFrame(mainMethod);
    frame->getLocalVars()->setRef(0, argsArr);
    m_mainThread->pushFrame(frame);
    Interperter::interpret(m_mainThread, m_cmd->m_verboseInstFlag);
}

rt::Object* JVM::createArgsArray() {
    string clsName("java/lang/String");
    rt::Class *clsString = m_classLoader->loadClass(&clsName);
    rt::Object *argsArr = clsString->getArrayClass()->newArrayObject(3);
    refArray slotArray = (refArray)argsArr->getRefs();
    for (int i = 0; i < 3; ++i) {
        rt::Object* obj = rt::StringPool::getJString(m_classLoader, m_cmd->m_args[i]);
        slotArray[i] = obj;
    }
    return argsArr;
}