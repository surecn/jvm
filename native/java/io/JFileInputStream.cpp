//
// Created by 郑邦国 on 2019/1/23.
//

#include "JFileInputStream.h"
#include "../../Registry.h"


namespace native {

    void JFileInputStream::init() {
        string clsName("java/io/FileInputStream");
        string methodName("initIDs");
        string methodDescriptor("()V");
        Registry::registerNative(clsName, methodName, methodDescriptor, &JFileInputStream::initIDs);
    }

    void JFileInputStream::initIDs(rt::Frame *frame) {
    }

}