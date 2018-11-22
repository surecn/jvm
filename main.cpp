#include "common.h"
#include "MainParamater.h"
#include "classpath/ClassPath.h"
#include "classfile/ClassFile.h"


const string PATHSeparter;

using namespace classpath;

void printUsage() {
    cout << "Usage : " << "" << "[-option] class [args...]\n";
}

void printLoadError(int error) {
    cout << "LoadClass : " << error;
}

cls::ClassFile* loadClass(string className, ClassPath* classPath) {
    classpath::ClassData classData;
    classPath->readClass(className, classData);
    if (classData.error != 0) {
        printLoadError(classData.error);
    }

    cls::ClassFile *classFile = new cls::ClassFile(classData.data);
    return classFile;
}


void startVM(struct MainParamater cmd) {
    ClassPath* classPath = new ClassPath(cmd.XjreOption, cmd.cpOption);
    string className = cmd.className;
    StrUtils::replace(className, ".", "/");

    cls::ClassFile* classFile = loadClass(className, classPath);

    cout << "startVM";
}


int main(int argc, char *argv[]) {
    cout << 0xca << endl;
    cout << (((unsigned int)0xca << 24) + ((unsigned int)0xfe << 16) + ((unsigned int)0xba << 8) + ((unsigned int)0xbe) ) << endl;
    cout << 0xcafebabe << " " << ((0xcafebabe & 0xff000000) >> 24 ) << " " << ((0xcafebabe & 0x00ff0000) >> 16)  << " " << ((0xcafebabe & 0x0000ff00) >> 8) << " " << (0xcafebabe & 0x000000ff) << endl;
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



