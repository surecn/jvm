//
// Created by 郑邦国 on 2018/10/30.
//

#ifndef JVM_ENTRY_H
#define JVM_ENTRY_H

#include <list>
#include "../common.h"

namespace classpath {
    class DirEntry;
    class Entry;

    struct ClassData {
        byte *data;
        Entry *entry;
        int error = 1;

        ~ClassData() {
            delete data;
        }
    };

    class Entry {
    public:
        virtual void readClass(string &path, ClassData &data) = 0;

        string toString();

        static Entry* create(string &path);

    };

    class DirEntry : public Entry {
    private:
        string path;

    public:

        DirEntry(string &s) : path(s)
        {}

        void readClass(string &path, ClassData &data);

        string toString();

        inline string apply(string &fileName) {
            return path + PATH_SEPARATOR + fileName;
        }

    };

    class CompositeEntry : public Entry {

    private:
        /*析构函数释放*/
        list<Entry*> entryList;
    public:
        CompositeEntry(string &path);

        virtual void readClass(string &path, classpath::ClassData &data);

        ~CompositeEntry();
    };

    class WildcardEntry : public CompositeEntry {
    private:
        string parentPath;
    public:
        WildcardEntry(string &path);
    };

    class ZipEntry : public Entry {
    public:
        ZipEntry(string &path){}
        void readClass(string &path, ClassData &data);

    };


}

#endif //JVM_ENTRY_H
