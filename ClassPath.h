//
// Created by 郑邦国 on 2018/10/9.
//

#ifndef JVM_CLASSPATH_H
#define JVM_CLASSPATH_H


#include "common.h"
#include "Entry.h"

class ClassPath {
private:
    Entry bootClassPath;
    Entry extClassPath;
    Entry userClassPath;
public:


    void parse(string jreOption, string cpOption) {
        parseBootAndExtClassPath(jreOption);
        parseBootAndExtClassPath(cpOption);
    }

    void parseBootAndExtClassPath(string jreOption) {

    }

    void parseUserClassPath(string cpOption) {

    }
};




#endif //JVM_CLASSPATH_H
