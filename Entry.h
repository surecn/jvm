//
// Created by 郑邦国 on 2018/10/30.
//

#ifndef JVM_ENTRY_H
#define JVM_ENTRY_H

#include "common.h"

class DirEntry;

class Entry {
public:
    virtual void readClass(string);

    virtual string toString();

    static Entry* newEntry(string);

    void newCompositeEntry(string, Entry[]);
};

class DirEntry : public Entry {
private:
    string path;

public:

    DirEntry(string s) : path(s)
    {}

    virtual void readClass(string cls);

    virtual string toString();

};


#endif //JVM_ENTRY_H
