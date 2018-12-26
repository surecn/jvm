//
// Created by 郑邦国 on 2018/12/21.
//

#include "ClassLoader.h"
#include "ConstantPool.h"

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
        if (data.m_error == 0) {
            cout << "java.lang.ClassNotFoundException: " << *name << endl;
        }
    }

    Class* ClassLoader::defineClass(u1 *data) {
        Class* cls = parseClass(data);
        cls->setClassLoader(this);
        resolveSuperClass(cls);
        resolveInterfaces(cls);
        return cls;
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

    void ClassLoader::prepare(rt::Class *cls) {
        calcInstanceFieldSlotIds(cls);
        calcStaticFieldSlotIds(cls);
        allocAndInitStaticVars(cls);
    }

    void ClassLoader::calcInstanceFieldSlotIds(rt::Class *cls) {
        u4 slotId = 0;
        Class* superClass = cls->getSuperClass();
        if (superClass != NULL) {
            slotId = superClass->getInstanceSlotCount();
        }
        Field** fields = cls->getFields();
        u4 fieldCount = cls->getFieldCount();
        for (int i = 0; i < fieldCount; ++i) {
            if (!fields[i]->isStatic()) {
                fields[i]->setSlotId(slotId);
                slotId++;
                if (fields[i]->isLongOrDouble()) {
                    slotId++;
                }
            }
        }
        cls->setInstanceSlotCount(slotId);
    }

    void ClassLoader::calcStaticFieldSlotIds(rt::Class *cls) {
        u4 slotId = 0;
        Field** fields = cls->getFields();
        u4 fieldCount = cls->getFieldCount();
        for (int i = 0; i < fieldCount; ++i) {
            if (fields[i]->isStatic()) {
                fields[i]->setSlotId(slotId);
                slotId++;
                if (fields[i]->isLongOrDouble()) {
                    slotId++;
                }
            }
        }
        cls->setStaticSlotCount(slotId);
    }

    void ClassLoader::allocAndInitStaticVars(rt::Class *cls) {
        SlotArray *slotArray = new SlotArray(cls->getStaticSlotCount());
        cls->setStaticVars(slotArray);
        Field** fields = cls->getFields();
        u4 fieldCount = cls->getFieldCount();
        for (int i = 0; i < fieldCount; ++i) {
            if (fields[i]->isStatic() && fields[i]->isFinal()) {
                initStaticFinalVar(cls, fields[i]);
            }
        }
    }

    void ClassLoader::initStaticFinalVar(rt::Class *cls, rt::Field *field) {
        SlotArray * slotArray = cls->getStaticVars();
        rt::ConstantPool *cp = cls->getConstantPool();
        u4 cpIndex = field->getConstValueIndex();
        u4 slotId = field->getSlotId();
        if (cpIndex > 0) {
            string *s = field->getDescriptor();
            if (*s == "Z" || *s == "B" || *s == "C" || *s == "S" || *s == "I") {
                java_int *val = (java_int *)cp->getConstant(cpIndex);
                slotArray->setInt(slotId, *val);
            } else if (*s == "J") {
                java_long *val = (java_long *)cp->getConstant(cpIndex);
                slotArray->setLong(slotId, *val);
            } else if (*s == "F") {
                java_float *val = (java_float *)cp->getConstant(cpIndex);
                slotArray->setFloat(slotId, *val);
            } else if (*s == "D") {
                java_double *val = (java_double *)cp->getConstant(cpIndex);
                slotArray->setDouble(slotId, *val);
            } else if (*s == "Ljava/lang/String;") {
                cout << "todo" << endl;//TODO 第八章实现
            }
        }
    }

    Class* ClassLoader::loadClass(string *name) {
        Class *cls =m_classMap[*name];
        if(cls != NULL) {
            return cls;
        }
        return loadNonArrayClass(name);
    }


}

