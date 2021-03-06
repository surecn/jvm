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
    string m_className;
    bool m_helpFlag;
    bool m_versionFlag;
    string m_xjreOption;
    string m_cpOption;
    string *m_args;
    bool m_verboseClassFlag;
    bool m_verboseInstFlag;

    MainParamater(int argc, char *argv[]) {
        m_className = argv[1];
        cout << "argc:" << argc << " className:" << m_className << endl;
        m_args = new string[4]{"2132", "3453453", "43545"};
        m_helpFlag = false;
        m_versionFlag = false;
        m_verboseClassFlag = false;
        m_verboseInstFlag = false;

        for (int i = 2; i < argc; ++i) {
            char * ch = argv[i];
            printf("argc:%s   \n", ch);
            string sKey(ch);
            if (sKey == "-h") {
                m_helpFlag = true;
                return;
            } else if (sKey == "-v") {
                m_versionFlag = true;
                return;
            } else if (sKey == "-cp" || sKey == "-classpath") {
                i++;
                char * ch = argv[i];
                string sValue(ch);
                m_cpOption = sValue;
            } else if (sKey == "Xjre") {
                i++;
                char * ch = argv[i];
                string sValue(ch);
                m_xjreOption = sValue;
            } else if (sKey == "verbose" || sKey == "verbose:class") {
                i++;
                m_verboseClassFlag = true;
            } else if (sKey == "verbose:inst") {
                i++;
                m_verboseInstFlag = true;
            } else {
                m_helpFlag = true;
            }
        }
    }

};


#endif //JVM_MAINARGS_H
