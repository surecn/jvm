//
// Created by 郑邦国 on 2018/10/30.
//

#ifndef JVM_ENTRY_H
#define JVM_ENTRY_H

#include <list>
#include "../common.h"

namespace cp {
    class DirEntry;
    class Entry;

    struct ClassData {
<<<<<<< HEAD
<<<<<<< HEAD
        byte *data;
        Entry *entry;
        int error = 1;
=======
=======
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
        byte *m_data;
        int m_error = 0;
        ClassData() {
            m_data = NULL;
            m_error = 0;
        }
        ~ClassData();
<<<<<<< HEAD
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
=======
>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
    };

    class Entry {
    public:
        virtual void readClass(string &path, ClassData &data) = 0;
<<<<<<< HEAD
<<<<<<< HEAD

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
        list<Entry*> entryList;
    public:
        CompositeEntry(string &path);

        virtual void readClass(string &path, classpath::ClassData &data);
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


=======
        string toString();
        static Entry* create(string &path);
    };

>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
=======
        string toString();
        static Entry* create(string &path);
    };

>>>>>>> f421e90f969fa8cd9d8d4aaa8d2536e048152b7e
}

#endif //JVM_ENTRY_H
