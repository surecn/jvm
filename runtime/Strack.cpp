//
// Created by 郑邦国 on 2018/11/22.
//

#include "Strack.h"

namespace rt {

    Strack* Strack::newStrack(int maxSize) {
        return new Strack(maxSize);
    }

    void Strack::push(rt::Frame *frame) {
        if (size > maxSize) {
            cout << "StrackOverflowError" << endl;
        }
        if (_top != NULL) {
            frame->lower = _top;
        }
        _top = frame;
        size++;
    }

    Frame* Strack::pop() {
        if (_top == NULL) {
            cout << "jvm strack is empty";
        }
        Frame* temp = _top;
        _top = _top->lower;
        temp->lower = NULL;
        size--;
        return temp;
    }

    Frame* Strack::top() {
        if (_top == NULL) {
            cout << "jvm strack is empty";
        }
        return _top;
    }

}