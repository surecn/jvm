#include "common.h"
#include "MainParamater.h"
#include "classpath/ClassPath.h"
#include "classfile/ClassFile.h"
#include "Interperter.h"
#include "runtime/heap/ClassLoader.h"
#include "common/ZipUtils.h"

const string PATHSeparter;

<<<<<<< HEAD
<<<<<<< HEAD
using namespace classpath;
=======
using namespace cp;
using namespace cf;
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
=======
using namespace cp;
using namespace cf;
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e

void printUsage() {
    cout << "Usage : " << "" << "[-option] class [args...]\n" << endl;
}

void printLoadError(int error) {
<<<<<<< HEAD
<<<<<<< HEAD
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
=======
    cout << "LoadClass : " << error << endl;
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
}

void startVM(struct MainParamater cmd) {
<<<<<<< HEAD
    ClassPath* classPath = new ClassPath(cmd.XjreOption, cmd.cpOption);
    string className = cmd.className;
    StrUtils::replace(className, ".", "/");

    cls::ClassFile* classFile = loadClass(className, classPath);
=======
=======
    cout << "LoadClass : " << error << endl;
}

void startVM(struct MainParamater cmd) {
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
    ClassPath classPath(cmd.m_xjreOption, cmd.m_cpOption);
    rt::ClassLoader *classLoader = new rt::ClassLoader(&classPath);

    string className = cmd.m_className;
    StrUtils::replace(className, ".", "/");

    rt::Class *mainClass = classLoader->loadClass(&className);
    rt::Method *mainMethod = mainClass->getMainMethod();
    if (mainMethod != NULL) {
        Interperter::interpret(mainMethod);
    }
<<<<<<< HEAD
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
=======
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e

    cout << "startVM" << endl;
}


int main(int argc, char *argv[]) {
    cout << 0xca << endl;
    cout << (((unsigned int)0xca << 24) + ((unsigned int)0xfe << 16) + ((unsigned int)0xba << 8) + ((unsigned int)0xbe) ) << endl;
    cout << 0xcafebabe << " " << ((0xcafebabe & 0xff000000) >> 24 ) << " " << ((0xcafebabe & 0x00ff0000) >> 16)  << " " << ((0xcafebabe & 0x0000ff00) >> 8) << " " << (0xcafebabe & 0x000000ff) << endl;
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



