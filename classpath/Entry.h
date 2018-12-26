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
        int m_error = 0;
        ~ClassData();
    };

    class Entry {
    public:
        virtual void readClass(string &path, ClassData &data) = 0;
        string toString();
        static Entry* create(string &path);
    };

}

#endif //JVM_ENTRY_H
