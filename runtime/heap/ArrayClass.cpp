//
// Created by 郑邦国 on 2019/1/3.
//

#include "ArrayClass.h"
#include "../../runtime/heap/ClassLoader.h"

namespace rt {

    Object* ArrayClass::newArrayObject(java_int count) {
        if (!isArray()) {
            logError("Not Array class: " + *getName());
            return NULL;
        }
        string name = *getName();
        if (name == "[Z") {
            return new Object(this, new java_bool[count], count);
        } else if (name == "[B") {
            return new Object(this, new java_byte[count], count);
        } else if (name == "[C") {
            return new Object(this, new java_char[count], count);
        } else if (name == "[S") {
            return new Object(this, new java_short[count], count);
        } else if (name == "[I") {
            return new Object(this, new java_int[count], count);
        } else if (name == "[J") {
            return new Object(this, new java_long[count], count);
        } else if (name == "[F") {
            return new Object(this, new java_float[count], count);
        } else if (name == "[D") {
            return new Object(this, new java_double[count], count);
        } else {
            void **obj = new void*[count];
            return new Object(this, obj, count);
        }
    }

    Class* ArrayClass::getComponentClass() {
        string componentClassName = getComponentClassName(*getName());
        return getClassLoader()->loadClass(&componentClassName);
    }

    string ArrayClass::getComponentClassName(string className) {
        if (className[0] == '[') {
            string compoentTypeDescriptor = className.substr(1, className.length() - 1);
            return toClassName(compoentTypeDescriptor);
        }
        logError("Not Array: " + className);
        return "";
    }

    string ArrayClass::toClassName(string descriptor) {
        if (descriptor[0] == '[') {
            return descriptor;
        } else if (descriptor[0] == 'L') {
            return descriptor.substr(1, descriptor.length() - 2);
        }
        map<string, string>* primitiveTypes = Class::getPrimitiveTypes();
        map<string, string>::iterator iter = primitiveTypes->begin();
        while (iter != primitiveTypes->end()) {
            if (iter->second == descriptor) {
                return iter->first;
            }
            iter++;
        }
        logError("Invalid descriptor: " + descriptor);
        return "";
    }

}