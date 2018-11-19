//
// Created by 郑邦国 on 2018/10/9.
//

#ifndef JVM_CLASSPATH_H
#define JVM_CLASSPATH_H


#include "../common.h"
#include "Entry.h"


namespace classpath {

    class ClassPath {
    private:
        DirEntry *bootClassPath;
        DirEntry *extClassPath;
        DirEntry *userClassPath;
    public:


        void parseBootAndExtClassPath(string jreOption);

        void parseUserClassPath(string cpOption);

        void readClass(string className, struct ClassData &data);

        static ClassPath* parse(string jreOption, string cpOption) {
            ClassPath* classPath = new ClassPath();
            classPath->parseBootAndExtClassPath(jreOption);
            classPath->parseBootAndExtClassPath(cpOption);
            return classPath;
        }
    };

};




#endif //JVM_CLASSPATH_H
