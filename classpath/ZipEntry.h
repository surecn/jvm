//
// Created by 郑邦国 on 2018/12/25.
//

#ifndef JVM_ZIPENTRY_H
#define JVM_ZIPENTRY_H


#include "Entry.h"

namespace cp {

    class ZipEntry : public Entry {
    private:
        string m_path;
    public:
        ZipEntry(string &path);
        void readClass(string &path, ClassData &data);

    };

}


#endif //JVM_ZIPENTRY_H
