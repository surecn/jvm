//
// Created by 郑邦国 on 2018/12/25.
//

#ifndef JVM_A_H
#define JVM_A_H


#include "CompositeEntry.h"

namespace cp {

    class WildcardEntry : public CompositeEntry {
    private:
        string m_path;
    public:
        WildcardEntry(string &path);
    };


}


#endif //JVM_A_H
