#include "common.h"
#include "MainParamater.h"
#include "classpath/ClassPath.h"
#include "classfile/ClassFile.h"
#include "Interperter.h"
#include "runtime/heap/ClassLoader.h"
#include "common/ZipUtils.h"
#include "runtime/heap/StringPool.h"

const string PATHSeparter;

using namespace cp;
using namespace cf;

void printUsage() {
    cout << "Usage : " << "" << "[-option] class [args...]\n" << endl;
}

void printLoadError(int error) {
    cout << "LoadClass : " << error << endl;
}

void startVM(struct MainParamater cmd) {
    ClassPath classPath(cmd.m_xjreOption, cmd.m_cpOption);
    rt::ClassLoader classLoader(&classPath, cmd.m_verboseClassFlag);

    string className = cmd.m_className;
    StrUtils::replace(className, ".", "/");

    rt::Class *mainClass = classLoader.loadClass(&className);
    rt::Method *mainMethod = mainClass->getMainMethod();
    if (mainMethod != NULL) {
        Interperter::interpret(mainMethod, cmd.m_verboseInstFlag, cmd.m_args);
    }

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



