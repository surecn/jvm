//
// Created by 郑邦国 on 2019/1/22.
//

#include "JFileOutputStream.h"
#include "../../Registry.h"


namespace native {

    void JFileOutputStream::init() {
        string clsName("java/io/FileOutputStream");
        string methodName("writeBytes");
        string methodDescriptor("([BIIZ)V");
        Registry::registerNative(clsName, methodName, methodDescriptor, &JFileOutputStream::writeBytes);
        Registry::registerNative(clsName, "initIDs", "()V", &JFileOutputStream::initIDs);
    }

    void JFileOutputStream::writeBytes(rt::Frame *frame) {
        rt::LocalVars *localVars = frame->getLocalVars();
        rt::Object *b = static_cast<rt::Object *>(localVars->getRef(1));
        java_int off = localVars->getInt(2);
        java_int len = localVars->getInt(3);

        u1 *jBytes = (u1 *)b->getData();
        cout << jBytes << endl;
    }

    void JFileOutputStream::initIDs(rt::Frame *frame) {
    }

}