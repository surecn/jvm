#include "common.h"
#include "MainParamater.h"
#include "classpath/ClassPath.h"
#include "classfile/ClassFile.h"
#include "Interperter.h"

const string PATHSeparter;

using namespace cp;
using namespace cf;

void printUsage() {
    cout << "Usage : " << "" << "[-option] class [args...]\n" << endl;
}

void printLoadError(int error) {
    cout << "LoadClass : " << error << endl;
}

void loadClass(string &className, ClassPath &classPath, ClassFile &classFile) {
    ClassData classData;
    classPath.readClass(className, classData);
    if (classData.m_error != 0) {
        printLoadError(classData.m_error);
    }

    classFile.parse(classData.m_data);
}

MemberInfo* getMainMethod(ClassFile* classFile) {
    for (int i = 0, len = classFile->getMethodCount(); i < len; ++i) {
        cf::MemberInfo* member = classFile->getMethods()[i];
        string *name = classFile->getName(member);
        string *descriptor = classFile->getDescriptor(member);
        if (*name == "main" && *descriptor == "([Ljava/lang/String;)V") {
            return member;
        }
    }
    return NULL;
}


void startVM(struct MainParamater cmd) {
    ClassPath classPath(cmd.m_xjreOption, cmd.m_cpOption);
    string className = cmd.m_className;
    StrUtils::replace(className, ".", "/");

    ClassFile classFile;
    loadClass(className, classPath, classFile);

    cf::MemberInfo* memberInfo = getMainMethod(&classFile);
    Interperter::interpret(memberInfo);

    cout << "startVM" << endl;
}


int main(int argc, char *argv[]) {
    MainParamater mainParamater(argc, argv);

    if (mainParamater.m_versionFlag) {
        cout << "0.0.1" << endl;
    } else if (mainParamater.m_helpFlag || mainParamater.m_className == "") {
        printUsage();
    } else {
        startVM(mainParamater);
    }
    return 0;
}



