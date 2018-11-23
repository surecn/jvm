//
// Created by 郑邦国 on 2018/11/23.
//

#ifndef JVM_CONSTANT_H
#define JVM_CONSTANT_H


#include "Instruction.h"

namespace rt {

    class Constant {
    private:

    };

    class NOP : public NoOperandsInstruction {
    public:
        void execute(rt::Frame* frame);
    };

    class ACONST_NULL : public NoOperandsInstruction {

    };

    class DCONST_0 : public NoOperandsInstruction {

    };

    class DCONST_1 : public NoOperandsInstruction {

    };

    class FCONST_0 : public NoOperandsInstruction {

    };

    class FCONST_1 : public NoOperandsInstruction {

    };

    class ICONST_M1 : public NoOperandsInstruction {

    };

    class ICONST_0 : public NoOperandsInstruction {

    };

    class ICONST_1 : public NoOperandsInstruction {

    };

    class ICONST_2 : public NoOperandsInstruction {

    };

    class ICONST_3 : public NoOperandsInstruction {

    };

    class ICONST_4 : public NoOperandsInstruction {

    };

    class ICONST_5 : public NoOperandsInstruction {

    };

    class LCONST_0 : public NoOperandsInstruction {

    };

    class LCONST_1 : public NoOperandsInstruction {

    };

}

#endif //JVM_CONSTANT_H
