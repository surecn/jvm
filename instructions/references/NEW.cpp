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
        ClassRef *classRef = (ClassRef*)cp->getConstant(m_index);
        Class *cls = classRef->resolvedClass();
        if (cls->isInterface() || cls->isAbstract()) {
            cout << "java.lang.InstantiationError" << endl;
        }
        java_ref ref = cls->newObject();
        frame->getOperandStack()->pushRef(ref);
    }

}