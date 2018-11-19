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
    string className;
    bool helpFlag;
    bool versionFlag;
    string XjreOption;
    string cpOption;
    string* args[];

    MainParamater(int argc, char *argv[]) {
        className = argv[1];
        cout << "argc:" << argc << " className:" << className << endl;
        for (int i = 2; i < argc; ++i) {
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
                cpOption = sValue;
            } else if (sKey == "Xjre") {
                i++;
                char * ch = argv[i];
                string sValue(ch);
                XjreOption = sValue;
            } else {
                helpFlag = true;
            }
        }
    }

};


#endif //JVM_MAINARGS_H
