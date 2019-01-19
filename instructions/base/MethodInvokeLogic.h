//
// Created by 郑邦国 on 2018/12/30.
//

#ifndef JVM_METHODINVOKELOGIC_H
#define JVM_METHODINVOKELOGIC_H


#include "../../runtime/Frame.h"

namespace rt {

    class MethodInvokeLogic {
    public:
        static void invokeMethod(Frame *frame, Method *method);
    };

}


#endif //JVM_METHODINVOKELOGIC_H
