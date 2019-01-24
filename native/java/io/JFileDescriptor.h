//
// Created by 郑邦国 on 2019/1/23.
//

#ifndef JVM_JFILEDESCRIPTOR_H
#define JVM_JFILEDESCRIPTOR_H


#include "../../../runtime/Frame.h"

namespace native {

    class JFileDescriptor {
    private:
    public:
        static void init();
        static void initIDs(rt::Frame *frame);
    };
}

#endif //JVM_JFILEDESCRIPTOR_H
