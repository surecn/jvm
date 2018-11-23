//
// Created by 郑邦国 on 2018/10/9.
//

#include "ClassPath.h"
#include <unistd.h>


using namespace classpath;

ClassPath::ClassPath(string &jreOption, string &cpOption) {
    parseBootAndExtClassPath(jreOption);
    parseUserClassPath(cpOption);
}

ClassPath::~ClassPath() {
    delete bootClassPath;
    delete extClassPath;
    delete userClassPath;
}

string getJreDir(string &jreOption) {
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

void ClassPath::parseBootAndExtClassPath(string &jreOption) {
    string jreDir = getJreDir(jreOption);

    // jre/lib/*
    string jreLibPath = jreDir.append("/lib/*");
    bootClassPath = new WildcardEntry(jreLibPath);

    // jre/lib/ext/*
    string jreExtPath = jreDir.append("/lib/ext/*");
    extClassPath = new WildcardEntry(jreExtPath);
}


void ClassPath::parseUserClassPath(string &cpOption) {
    if (cpOption=="") {
        cpOption = ".";
    }
    userClassPath = Entry::create(cpOption);
}


void ClassPath::readClass(string &className, ClassData &data) {
    string str = className + ".class";
    bootClassPath->readClass(str, data);
    if (data.error == 0) {
        return;
    }
    this->extClassPath->readClass(str, data);
    if (data.error == 0) {
        return;
    }
    this->userClassPath->readClass(str, data);
}
