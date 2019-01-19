//
// Created by 郑邦国 on 2018/12/21.
//

#ifndef JVM_CLASSLOADER_H
#define JVM_CLASSLOADER_H


#include "../../classpath/ClassPath.h"
#include "Class.h"
#include <map>


namespace rt {

    class ClassLoader {
    private:
        cp::ClassPath *m_classPath;
        static map<string,Class*> s_classMap;
        bool m_verboseFlag;
        Class* loadNonArrayClass(string *name);
        Class* loadArrayClass(string *name);
        void readClass(string *name, cp::ClassData &data);
        Class* defineClass(u1 *data);
        Class* parseClass(u1 *data);
        void resolveSuperClass(Class *cls);
        void resolveInterfaces(Class *cls);
        void link(Class *cls);
        void verity(Class *cls);
        void prepare(Class *cls);
        void calcInstanceFieldSlotIds(Class *cls);
        void calcStaticFieldSlotIds(Class *cls);
        void allocAndInitStaticVars(Class *cls);
        void initStaticFinalVar(Class *cls, Field* field);
        void loadBasicClasses();
        void loadPrimitiveClasses();
        void loadPrimitiveClass(string *className);
        void loadLibrary(Class *cls);
    public:
        ClassLoader(cp::ClassPath *classPath, bool verboseFlag);
        Class* loadClass(string *name);

    };

}


#endif //JVM_CLASSLOADER_H
