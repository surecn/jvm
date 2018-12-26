//
// Created by 郑邦国 on 2018/12/25.
//

#ifndef JVM_DIRENTRY_H
#define JVM_DIRENTRY_H

#include "../common.h"
#include "Entry.h"

namespace cp {

    class DirEntry : public Entry {
    private:
        string m_path;
    public:
        DirEntry(string &s);
        void readClass(string &path, ClassData &data);
        string toString();
        string apply(string &fileName);

    };

}


#endif //JVM_DIRENTRY_H
