//
// Created by 郑邦国 on 2018/10/9.
//

#ifndef JVM_CLASSPATH_H
#define JVM_CLASSPATH_H


#include "../common.h"
#include "Entry.h"


namespace cp {

    class ClassPath {
    private:
        Entry *m_bootClassPath;
        Entry *m_extClassPath;
        Entry *m_userClassPath;
    public:
        ClassPath(string &jreOption, string &cpOption);
        void parseBootAndExtClassPath(string &jreOption);
        void parseUserClassPath(string &cpOption);
        void readClass(string &className, struct ClassData &data);
        ~ClassPath();

    };

};




#endif //JVM_CLASSPATH_H
