//
// Created by 郑邦国 on 2019/1/22.
//

#ifndef JVM_JVM_H
#define JVM_JVM_H


#include "MainParamater.h"
#include "runtime/heap/ClassLoader.h"

class JVM {
private:
    MainParamater *m_cmd;
    rt::ClassLoader *m_classLoader;
    rt::Thread *m_mainThread;
    cp::ClassPath *m_cp;
public:
    JVM(MainParamater *cmd);
    ~JVM();
    void start();
    void initVM();
    void execMain();
    rt::Object* createArgsArray();
};


#endif //JVM_JVM_H
