#include "common.h"
#include "MainParamater.h"
#include "classpath/ClassPath.h"
#include "classfile/ClassFile.h"


const string PATHSeparter;

using namespace classpath;
using namespace cls;

void printUsage() {
    cout << "Usage : " << "" << "[-option] class [args...]\n";
}

void printLoadError(int error) {
    cout << "LoadClass : " << error;
}

ClassFile* loadClass(string className, ClassPath* classPath) {
    classpath::ClassData classData;
    classPath->readClass(className, classData);
    if (classData.error != 0) {
        printLoadError(classData.error);
    }

    ClassFile *classFile = new ClassFile();
    cls::ClassFile::ParseClassFile(classData.data, classFile);
    return classFile;
}


void startVM(struct MainParamater cmd) {
    ClassPath* classPath;
    classPath = ClassPath::parse(cmd.XjreOption, cmd.cpOption);
    string className = cmd.className;
    StrUtils::replace(className, "/", ".");

    ClassFile* classFile = loadClass(className, classPath);

    cout << "startVM";
}


int main(int argc, char *argv[]) {
    MainParamater mainParamater(argc, argv);

    if (mainParamater.versionFlag) {
        cout << "0.0.1";
    } else if (mainParamater.helpFlag || mainParamater.className == "") {
        printUsage();
    } else {
        startVM(mainParamater);
    }
    return 0;
}



