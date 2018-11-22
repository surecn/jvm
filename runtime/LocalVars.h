//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_LOCALVARS_H
#define JVM_LOCALVARS_H


class LocalVars {
private:
    int *local;

public:
    void setInt(int index, int val);
    int getInt(int index);

    void setLong(int index, long val);
    long getLong(int index);

    void setFloat(int index, float val);
    float getFloat(int index);

    void setDouble(int index, double val);
    double getDouble(int index);

    void setPtr(int index, int* val);
    int *getPtr(int index);
};


#endif //JVM_LOCALVARS_H
