//
// Created by 郑邦国 on 2018/11/22.
//

#include "Stack.h"
#include "Frame.h"

namespace rt {

    Stack* Stack::newStack(int maxSize) {
        return new Stack(maxSize);
    }

    Stack::Stack(int xss):m_maxSize(xss) {
        m_size = 0;
        m_top = NULL;
    }

    void Stack::push(rt::Frame *frame) {
        if (m_size > m_maxSize) {
            logError("StrackOverflowError");
        }
        if (m_top != NULL) {
            frame->m_lower = m_top;
        }
        m_top = frame;
        m_size++;
    }

    Frame* Stack::pop() {
        if (m_top == NULL) {
            logError("jvm strack is empty");
        }
        Frame* temp = m_top;
        m_top = m_top->m_lower;
        temp->m_lower = NULL;
        m_size--;
        return temp;
    }

    Frame* Stack::top() {
        if (m_top == NULL) {
            logError("jvm strack is empty");
        }
        return m_top;
    }

    bool Stack::isEmpty() {
        return m_top == NULL;
    }

    void Stack::clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    int Stack::getSize() {
        return m_size;
    }

}