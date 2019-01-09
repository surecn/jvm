//
// Created by 郑邦国 on 2018/11/30.
//

#ifndef JVM_SH_H
#define JVM_SH_H


#include "../base/Instruction.h"

namespace rt {

    /**
     * int 左位移
     */
    class ISHL : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    /**
     * int算术右位移
     */
    class ISHR : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    /**
     * int逻辑右位移
     */
    class IUSHR : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    /**
     * long左位移
     */
    class LSHL : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };


    /**
     * long算术右位移
     */
    class LSHR : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    /**
     * long逻辑右位移
     */
    class LUSHR : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

}


#endif //JVM_SH_H
