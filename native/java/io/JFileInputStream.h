//
// Created by 郑邦国 on 2019/1/23.
//

#ifndef JVM_JFILEINPUTSTREAM_H
#define JVM_JFILEINPUTSTREAM_H


#include "../../../runtime/Frame.h"

namespace native {

    class JFileInputStream {
    private:
    public:
        static void init();
        static void initIDs(rt::Frame *frame);
    };
}


#endif //JVM_JFILEINPUTSTREAM_H
