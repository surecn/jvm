//
// Created by 郑邦国 on 2018/10/9.
//

#include "ClassPath.h"
#include <unistd.h>


using namespace classpath;

string getJreDir(string jreOption) {
    if (jreOption != "" && access(jreOption.c_str(), F_OK)) { //TODO 判断目录是否存在
        return jreOption;
    }
    if (access("./jre", F_OK)) {
        return "./jre";
    }
    string javaHome(getenv("JAVA_HOME"));
    if (javaHome != "") {
        return javaHome + "/jre";
    }
    return NULL;
}

void ClassPath::parseBootAndExtClassPath(string jreOption) {
    string jreDir = getJreDir(jreOption);

    // jre/lib/*
    string jreLibPath = jreDir.append("/lib/*");
    bootClassPath = WildcardEntry::newWildcardEntry();

    // jre/lib/ext/*
    string jreExtPath = jreDir.append("/lib/ext/*");
    extClassPath = WildcardEntry::newWildcardEntry();
}


void ClassPath::parseUserClassPath(string cpOption) {

}


void ClassPath::readClass(string className, ClassData &data) {
    className += ".class";
    bootClassPath->readClass(className, data);
    if (data.error == 0) {
        return;
    }
    this->extClassPath->readClass(className, data);
    if (data.error == 0) {
        return;
    }
    this->userClassPath->readClass(className, data);
}
