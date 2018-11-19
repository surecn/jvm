//
// Created by 郑邦国 on 2018/10/30.
//

#ifndef JVM_ENTRY_H
#define JVM_ENTRY_H

#include "../common.h"

namespace classpath {
    class DirEntry;
    class Entry;

    struct ClassData {
        byte *data;
        Entry *entry;
        int error;
    };

    class Entry {
    public:
         void readClass(string, ClassData &data);

         string toString();

        Entry* newEntry(string);

        void newCompositeEntry(string, Entry*);
    };

    class DirEntry : public Entry {
    private:
        string path;

    public:

        DirEntry(string s) : path(s)
        {}

        void readClass(string, ClassData &data);

        string toString();

        inline string apply(string fileName) {
            return path + "/" + fileName;
        }

    };

}

#endif //JVM_ENTRY_H
