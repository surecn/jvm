//
// Created by 郑邦国 on 2018/11/22.
//

#include "LocalVars.h"
#include "../common.h"

namespace rt {

    java_int LocalVars::getInt(int index) {
        return local[index];
    }

    void LocalVars::setInt(int index, java_int val) {
        local[index] = val;
    }

    java_float LocalVars::getFloat(int index) {
        u1 ch[SIZE_INT];
        BytesUtils::intToBytes(local[index], ch);
        return BytesUtils::bytesToFloat(ch);
    }

    void LocalVars::setFloat(int index, java_float val) {
        u1 ch[SIZE_INT];
        BytesUtils::floatToBytes(val, ch);
        local[index] = BytesUtils::bytesToInt(ch);
    }

    java_long LocalVars::getLong(int index) {
        java_long low = local[index];
        java_long high = local[index + 1];
        return high << 32 | low;
    }

    void LocalVars::setLong(int index, java_long val) {
        java_int low = val;
        java_int high = val >> 32;
        local[index] = low;
        local[index + 1] = high;
    }

    java_double LocalVars::getDouble(int index) {
        java_long low = local[index];
        java_long high = local[index + 1];
        u1 ch[SIZE_INT];
        BytesUtils::intToBytes(low, ch);
        BytesUtils::intToBytes(low, ch + SIZE_INT);
        return BytesUtils::bytesToDouble(ch);
    }

    java_int* LocalVars::getPtr(int index) {
        return (java_int*)local[index];
    }

    void LocalVars::setPtr(int index, java_int *val) {
        local[index] = (java_int)val;
    }
}