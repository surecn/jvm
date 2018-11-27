//
// Created by 郑邦国 on 2018/11/22.
//

#include "Stack.h"

namespace rt {

    Stack* Stack::newStack(int maxSize) {
        return new Stack(maxSize);
    }

    void Stack::push(rt::Frame *frame) {
        if (size > maxSize) {
            cout << "StrackOverflowError" << endl;
        }
        if (_top != NULL) {
            frame->lower = _top;
        }
        _top = frame;
        size++;
    }

    Frame* Stack::pop() {
        if (_top == NULL) {
            cout << "jvm strack is empty";
        }
        Frame* temp = _top;
        _top = _top->lower;
        temp->lower = NULL;
        size--;
        return temp;
    }

    Frame* Stack::top() {
        if (_top == NULL) {
            cout << "jvm strack is empty";
        }
        return _top;
    }

}