//
// Created by 郑邦国 on 2018/11/22.
//

#include "Stack.h"

namespace rt {

    Stack* Stack::newStack(int maxSize) {
        return new Stack(maxSize);
    }

    void Stack::push(rt::Frame *frame) {
        if (m_size > m_maxSize) {
            cout << "StrackOverflowError" << endl;
        }
        if (m_top != NULL) {
            frame->lower = m_top;
        }
        m_top = frame;
        m_size++;
    }

    Frame* Stack::pop() {
        if (m_top == NULL) {
            cout << "jvm strack is empty";
        }
        Frame* temp = m_top;
        m_top = m_top->lower;
        temp->lower = NULL;
        m_size--;
        return temp;
    }

    Frame* Stack::top() {
        if (m_top == NULL) {
            cout << "jvm strack is empty";
        }
        return m_top;
    }


}