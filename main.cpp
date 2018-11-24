#include "common.h"
#include "MainParamater.h"
#include "classpath/ClassPath.h"
#include "classfile/ClassFile.h"


const string PATHSeparter;

using namespace cpath;
using namespace cls;

void printUsage() {
    cout << "Usage : " << "" << "[-option] class [args...]\n" << endl;
}

void printLoadError(int error) {
    cout << "LoadClass : " << error << endl;
}

void loadClass(string &className, ClassPath &classPath, ClassFile &classFile) {
    ClassData classData;
    classPath.readClass(className, classData);
    if (classData.error != 0) {
        printLoadError(classData.error);
    }

    classFile.load(classData.data);
}


void startVM(struct MainParamater cmd) {
    ClassPath classPath(cmd.XjreOption, cmd.cpOption);
    string className = cmd.className;
    StrUtils::replace(className, ".", "/");

    ClassFile classFile;
    loadClass(className, classPath, classFile);

    cout << "startVM" << endl;
}


int main(int argc, char *argv[]) {
    MainParamater mainParamater(argc, argv);

    if (mainParamater.versionFlag) {
        cout << "0.0.1" << endl;
    } else if (mainParamater.helpFlag || mainParamater.className == "") {
        printUsage();
    } else {
        startVM(mainParamater);
    }
    return 0;
}



