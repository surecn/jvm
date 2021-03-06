//
// Created by 郑邦国 on 2018/10/9.
//

#include "ClassPath.h"
#include <unistd.h>
#include "WildcardEntry.h"

namespace cp {

    ClassPath::ClassPath(string &jreOption, string &cpOption) {
        parseBootAndExtClassPath(jreOption);
        parseUserClassPath(cpOption);
    }

    ClassPath::~ClassPath() {
        delete m_bootClassPath;
        delete m_extClassPath;
        delete m_userClassPath;
    }

    string getJreDir(string &jreOption) {
        if (jreOption != "" && access(jreOption.c_str(), F_OK) != -1) { //TODO 判断目录是否存在
            return jreOption;
        }
        if (access("./jre", F_OK) != -1) {
            return "./jre";
        }
        char *c_javaHome = getenv("JAVA_HOME");
        string javaHome(c_javaHome);
        if (javaHome != "") {
            return javaHome + "/jre";
        }
        return NULL;
    }

    void ClassPath::parseBootAndExtClassPath(string &jreOption) {
        string jreDir = getJreDir(jreOption);
        // jre/lib/*
        string jreLibPath = (string(jreDir)).append("/lib/*");
        m_bootClassPath = new WildcardEntry(jreLibPath);

        // jre/lib/ext/*
        string jreExtPath = (string(jreDir)).append("/lib/ext/*");
        m_extClassPath = new WildcardEntry(jreExtPath);
    }


    void ClassPath::parseUserClassPath(string &cpOption) {
        if (cpOption == "") {
            cpOption = ".";
        }
        m_userClassPath = Entry::create(cpOption);
    }


    void ClassPath::readClass(string &className, ClassData &data) {
        string str = className + ".class";
        m_bootClassPath->readClass(str, data);
        if (data.m_error == 1) {
            return;
        }
        this->m_extClassPath->readClass(str, data);
        if (data.m_error == 1) {
            return;
        }
        this->m_userClassPath->readClass(str, data);
    }
}
