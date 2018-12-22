//
// Created by 郑邦国 on 2018/12/21.
//

#include "ClassLoader.h"

namespace rt {

    ClassLoader::ClassLoader(cp::ClassPath *classPath) {
        m_classPath = classPath;
    }

    Class* ClassLoader::loadNonArrayClass(string *name) {
        cp::ClassData data;
        readClass(name, data);
        Class *cls = defineClass(data.m_data);
        link(cls);
        cout << "[Loaded " << name << " from " << endl;
        return cls;
    }

    void ClassLoader::readClass(string *name, cp::ClassData &data) {
        m_classPath->readClass(*name, data);
        if (data.m_error != NULL) {
            cout << "java.lang.ClassNotFoundException: " << *name << endl;
        }
    }

    Class* ClassLoader::defineClass(u1 *data) {
        Class* cls = parseClass(data);
        cls->setClassLoader(this);
        resolveSuperClass(cls);
        resolveInterfaces(cls);
    }

    Class* ClassLoader::parseClass(u1 *data) {
        cf::ClassFile classFile;
        classFile.parse(data);
        return new Class(&classFile);
    }

    void ClassLoader::resolveSuperClass(rt::Class *cls) {
        if ("java/lang/Object" != *cls->getName()) {
            cls->setSuperClass(cls->getClassLoader()->loadClass(cls->getSuperClassName()));
        }
    }

    void ClassLoader::resolveInterfaces(rt::Class *cls) {
        u2 interfaceCount = cls->getInterfaceCount();
        if (interfaceCount > 0) {
            string **interfaceNames = cls->getInterfaceNames();
            Class **interfaces = new Class*[interfaceCount];
            for (int i = 0; i < interfaceCount; ++i) {
                interfaces[i] = cls->getClassLoader()->loadClass(interfaceNames[i]);
            }
            cls->setInterfaces(interfaces);
        }
    }

    void ClassLoader::link(rt::Class *cls) {
        verity(cls);
        prepare(cls);
    }

    void ClassLoader::verity(rt::Class *cls) {

    }

    Class* ClassLoader::loadClass(string *name) {
        Class *cls =m_classMap[*name];
        if(cls != NULL) {
            return cls;
        }
        return loadNonArrayClass(name);
    }


}

