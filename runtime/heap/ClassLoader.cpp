//
// Created by 郑邦国 on 2018/12/21.
//

#include "ClassLoader.h"
#include "ConstantPool.h"
#include "AccessFlags.h"
#include "StringPool.h"
#include "ConstantPool.h"

namespace rt {

    map<string,Class*> ClassLoader::s_classMap;

    ClassLoader::ClassLoader(cp::ClassPath *classPath, bool verboseFlag) {
        m_classPath = classPath;
        m_verboseFlag = verboseFlag;
        loadBasicClasses();
        loadPrimitiveClasses();
    }

    void ClassLoader::loadBasicClasses() {
        string s("java/lang/Class");
        Class *jClass = loadClass(&s);
        map<string, Class*>::iterator iter = s_classMap.begin();
        while (iter != s_classMap.end()) {
            Object *obj = new Object(jClass);
            obj->setExtra(jClass);
            iter->second->setJClass(obj);
            iter++;
        }
    }

    void ClassLoader::loadPrimitiveClasses() {
        map<string, string>* types = Class::getPrimitiveTypes();
        map<string, string>::iterator iter = types->begin();
        while (iter != types->end()) {
            string s = iter->first;
            loadPrimitiveClass(&s);
            iter++;
        }
    }

    void ClassLoader::loadPrimitiveClass(string *className) {
        string *newClsName = new string(*className);
        Class *cls = new Class(ACC_PUBLIC, newClsName, this, true, NULL, NULL, 0);
        cls->setJClass(new Object(s_classMap["java/lang/Class"]));
        cls->getJClass()->setExtra(cls);
        s_classMap[*newClsName] = cls;
    }

    Class* ClassLoader::loadNonArrayClass(string *name) {
        cp::ClassData data;
        readClass(name, data);
        Class *cls = defineClass(data.m_data);
        link(cls);
        if (m_verboseFlag) {
            cout << "[Loaded " << *name << " from " << endl;
        }
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
        s_classMap[*cls->getName()] = cls;
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
                java_int val = cp->getInteger(cpIndex);
                slotArray->setInt(slotId, val);
            } else if (*s == "J") {
                java_long val =  cp->getLong(cpIndex);
                slotArray->setLong(slotId, val);
            } else if (*s == "F") {
                java_float val = cp->getFloat(cpIndex);
                slotArray->setFloat(slotId, val);
            } else if (*s == "D") {
                java_double val = cp->getDouble(cpIndex);
                slotArray->setDouble(slotId, val);
            } else if (*s == "Ljava/lang/String;") {
                string *str = cp->getString(cpIndex);
                Object *jStr = StringPool::getJString(cls->getClassLoader(), *str);
                slotArray->setRef(slotId, jStr);
            } else {
                slotArray->setRef(slotId, NULL);
            }
        }
    }

    Class* ClassLoader::loadClass(string *name) {
        Class *cls = s_classMap[*name];
        if(cls != NULL) {
            return cls;
        }
        if ((*name)[0] == '[') {
            cls = loadArrayClass(name);
        } else {
            cls = loadNonArrayClass(name);
        }
        Class *clsClass = s_classMap["java/lang/Class"];
        if (clsClass != NULL) {
            Object * jobj = new Object(clsClass);
            jobj->setExtra(cls);
            cls->setJClass(jobj);
        }
        return cls;
    }


    Class* ClassLoader::loadArrayClass(string *name) {
        string sObj("java/lang/Object");
        string sCloneable("java/lang/Cloneable");
        string sSerializable("java/io/Serializable");
        Class *superClass = loadClass(&sObj);
        Class *clsCloneable = loadClass(&sCloneable);
        Class *clsSerializable = loadClass(&sSerializable);
        string *newName = new string(*name);
        Class* cls = new Class(ACC_PUBLIC, newName, this, true, superClass, new Class*[2]{clsCloneable, clsSerializable}, 2);
        s_classMap[*newName] = cls;
        return cls;
    }

    void ClassLoader::loadLibrary(Class *cls) {
        if (*cls->getName() == "java/lang/ClassLoader") {

        }
    }


}

