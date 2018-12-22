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
        byte *m_data;
        Entry *m_entry;
        int m_error = 1;
        ~ClassData();
    };

    class Entry {
    public:
        virtual void readClass(string &path, ClassData &data) = 0;
        string toString();
        static Entry* create(string &path);
    };

    class DirEntry : public Entry {
    private:
        string m_path;
    public:
        DirEntry(string &s);
        void readClass(string &path, ClassData &data);
        string toString();
        string apply(string &fileName);

    };

    class CompositeEntry : public Entry {
    private:
        list<Entry*> m_entryList;/*析构函数释放*/
    public:
        CompositeEntry(string &path);
        ~CompositeEntry();
        virtual void readClass(string &path, ClassData &data);
    };

    class WildcardEntry : public CompositeEntry {
    private:
        string m_parentPath;
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
