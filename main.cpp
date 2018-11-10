#include "common.h"
#include "MainParamater.h"
#include "ClassPath.h"


const string PATHSeparter;


void printUsage() {
    cout << "Usage : " << "" << "[-option] class [args...]\n";
}

void startVM(struct MainParamater cmd) {
    ClassPath classPath;
    classPath.parse(cmd.XjreOption, cmd.cpOption);
    cout << "startVM";
}

int main(int argc, char *argv[]) {
    MainParamater mainParamater(argc, argv);

    if (mainParamater.versionFlag) {
        cout << "0.0.1";
    } else if (mainParamater.helpFlag || mainParamater.classPath == "") {
        printUsage();
    } else {
        startVM(mainParamater);
    }
    return 0;
}



