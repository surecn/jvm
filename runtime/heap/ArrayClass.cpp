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
            java_bool * arr = new java_bool[count];
            for (int i = 0; i < count; ++i) {
                arr[i] = 0;
            }
            return new Object(this, arr, count);
        } else if (name == "[B") {
            java_byte * arr = new java_byte[count];
            for (int i = 0; i < count; ++i) {
                arr[i] = 0;
            }
            return new Object(this, arr, count);
        } else if (name == "[C") {
            java_char * arr = new java_char[count];
            for (int i = 0; i < count; ++i) {
                arr[i] = 0;
            }
            return new Object(this, arr, count);
        } else if (name == "[S") {
            java_short * arr = new java_short[count];
            for (int i = 0; i < count; ++i) {
                arr[i] = 0;
            }
            return new Object(this, arr, count);
        } else if (name == "[I") {
            java_int * arr = new java_int[count];
            for (int i = 0; i < count; ++i) {
                arr[i] = 0;
            }
            return new Object(this, arr, count);
        } else if (name == "[J") {
            java_long * arr = new java_long[count];
            for (int i = 0; i < count; ++i) {
                arr[i] = 0;
            }
            return new Object(this, arr, count);
        } else if (name == "[F") {
            java_float * arr = new java_float[count];
            for (int i = 0; i < count; ++i) {
                arr[i] = 0;
            }
            return new Object(this, arr, count);
        } else if (name == "[D") {
            java_double * arr = new java_double[count];
            for (int i = 0; i < count; ++i) {
                arr[i] = 0;
            }
            return new Object(this, arr, count);
        } else {
            void **obj = new void*[count];
            for (int i = 0; i < count; ++i) {
                obj[i] = NULL;
            }
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