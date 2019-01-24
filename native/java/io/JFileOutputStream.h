//
// Created by 郑邦国 on 2019/1/22.
//

#ifndef JVM_JFILEOUTPUTSTREAM_H
#define JVM_JFILEOUTPUTSTREAM_H


#include "../../../runtime/Frame.h"

namespace native {

    class JFileOutputStream {
    private:
    public:
        static void init();
        static void writeBytes(rt::Frame *frame);
        static void initIDs(rt::Frame *frame);
    };
}


#endif //JVM_JFILEOUTPUTSTREAM_H
