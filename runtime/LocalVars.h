//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_LOCALVARS_H
#define JVM_LOCALVARS_H

#include "../common.h"

namespace rt {

    class LocalVars {
    private:
        java_int *local;
        LocalVars(java_int val) {
            local = new java_int[val];
        }
    public:
        static LocalVars* newLocalVars(java_int val);

        void setInt(int index, java_int val);
        java_int getInt(int index);

        void setLong(int index, java_long val);
        java_long getLong(int index);

        void setFloat(int index, java_float val);
        java_float getFloat(int index);

        void setDouble(int index, java_double val);
        java_double getDouble(int index);

        void setRef(int index, java_ref val);
        java_ref getRef(int index);


    };


}

#endif //JVM_LOCALVARS_H
