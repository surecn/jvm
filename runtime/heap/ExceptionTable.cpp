//
// Created by 郑邦国 on 2019/1/21.
//

#include "ExceptionTable.h"
#include "ConstantPool.h"

namespace rt {

    ExceptionTable::ExceptionTable(cf::ExceptionTableEntry **entries, int length, rt::ConstantPool *cp) {
        m_exceptionHandlerList = new ExceptionHandler*[length];
        m_length = length;
        for (int i = 0; i < length; ++i) {
            m_exceptionHandlerList[i] = new ExceptionHandler();
            m_exceptionHandlerList[i]->startPC = entries[i]->getStartPc();
            m_exceptionHandlerList[i]->endPC = entries[i]->getEndPc();
            m_exceptionHandlerList[i]->handlerPC = entries[i]->getHandlerPc();
            m_exceptionHandlerList[i]->catchType = getCatchRef(entries[i]->getCatchType(), cp);
        }
    }

    ClassRef* ExceptionTable::getCatchRef(int index, rt::ConstantPool* cp) {
        if (index == 0) {
            return NULL;
        }
        return (ClassRef*)cp->getConstant(index);
    }

    ExceptionHandler* ExceptionTable::findExceptionHandler(rt::Class *exClass, int pc) {
        for (int i = 0; i < m_length; ++i) {
            ExceptionHandler *handler = m_exceptionHandlerList[i];
            if (pc >= handler->startPC && pc < handler->endPC) {
                if (handler->catchType == NULL) {
                    return handler;
                }
                Class *catchClass = handler->catchType->resolvedClass();
                if (catchClass == exClass || catchClass->isSuperClassOf(exClass)) {
                    return handler;
                }
            }
        }
        return NULL;
    }

}