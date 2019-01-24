//
// Created by 郑邦国 on 2019/1/23.
//

#include "JFileDescriptor.h"
#include "../../Registry.h"


namespace native {

    void JFileDescriptor::init() {
        string clsName("java/io/FileDescriptor");
        string methodName("initIDs");
        string methodDescriptor("()V");
        Registry::registerNative(clsName, methodName, methodDescriptor, &JFileDescriptor::initIDs);
    }

    void JFileDescriptor::initIDs(rt::Frame *frame) {
    }

}