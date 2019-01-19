//
// Created by 郑邦国 on 2018/12/23.
//

#include "NEW.h"
#include "../../runtime/heap/Class.h"
#include "../../runtime/heap/ConstantPool.h"
#include "../../runtime/heap/ClassRef.h"

namespace rt {

    void NEW::execute(rt::Frame *frame) {
        ConstantPool *cp = frame->getMethod()->getClass()->getConstantPool();
        ClassRef *classRef = cp->getClassRef(m_index);
        Class *cls = classRef->resolvedClass();

        if (!cls->isInitStarted()) {
            frame->revertNextPC();
            cls->initClass(frame->getThread());
            return;
        }

        if (cls->isInterface() || cls->isAbstract()) {
            cout << "java.lang.InstantiationError" << endl;
        }
        java_ref ref = new Object(cls);
        frame->getOperandStack()->pushRef(ref);
    }

}