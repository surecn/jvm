//
// Created by 郑邦国 on 2018/10/9.
//

#ifndef JVM_MAINARGS_H
#define JVM_MAINARGS_H

#include <iostream>
#include <string>

using namespace std;

class MainParamater {
private:

public:
    bool helpFlag;
    bool versionFlag;
    string XjreOption;
    string cpOption;
    string classPath;
    string* args[];

    MainParamater(int argc, char *argv[]) {
        printf("argc:%d\n", argc);
        for (int i = 1; i < argc; ++i) {
            char * ch = argv[i];
            printf("argc:%s   \n", ch);
            string sKey(ch);
            if (sKey == "-h") {
                helpFlag = true;
                return;
            } else if (sKey == "-v") {
                versionFlag = true;
                return;
            } else if (sKey == "-cp" || sKey == "-classpath") {
                i++;
                char * ch = argv[i];
                string sValue(ch);
                classPath = sValue;
            } else {
                helpFlag = true;
            }
        }
    }

};


#endif //JVM_MAINARGS_H
