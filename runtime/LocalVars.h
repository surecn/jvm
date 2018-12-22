//
// Created by 郑邦国 on 2018/11/22.
//

#ifndef JVM_LOCALVARS_H
#define JVM_LOCALVARS_H

#include "../common.h"
#include "../common/SlotArray.h"

namespace rt {

    class LocalVars : public SlotArray {
    public:
        LocalVars(java_int val);

    };


}

#endif //JVM_LOCALVARS_H
