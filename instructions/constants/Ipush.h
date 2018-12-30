//
// Created by 郑邦国 on 2018/12/14.
//

#ifndef JVM_IPUSH_H
#define JVM_IPUSH_H


#include "../base/Instruction.h"

namespace rt {

    class BIPUSH : public Instruction {
    private:
        u1 _val;
    public:
        void fetchOperand(BytecodeReader* reader);
        void execute(rt::Frame* frame);
        ~BIPUSH() {
            cout << "~BIPUSH:" << _val << endl;
        }
    };

}


#endif //JVM_IPUSH_H
