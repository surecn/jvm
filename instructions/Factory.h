//
// Created by 郑邦国 on 2018/12/10.
//

#ifndef JVM_FACTORY_H
#define JVM_FACTORY_H


#include "../common.h"
#include "base/Instruction.h"
#include "constants/CONSTANT.h"
#include "loads/ILOAD.h"
#include "loads/LLOAD.h"
#include "loads/FLOAD.h"
#include "loads/DLOAD.h"
#include "loads/ALOAD.h"
#include "stores/ISTORE.h"
#include "stores/LSTORE.h"
#include "stores/FSTORE.h"
#include "stores/DSTORE.h"
#include "stores/ASTORE.h"
#include "stack/POP.h"
#include "stack/DUP.h"
#include "stack/SWAP.h"
#include "math/ADD.h"
#include "math/SUB.h"
#include "math/MUL.h"
#include "math/DIV.h"
#include "math/REM.h"
#include "math/NEG.h"
#include "math/SH.h"
#include "math/AND.h"
#include "math/OR.h"
#include "math/XOR.h"
#include "conversions/I2X.h"
#include "conversions/L2X.h"
#include "conversions/F2X.h"
#include "conversions/D2X.h"
#include "comparisons/LCMP.h"
#include "comparisons/FCMP.h"
#include "comparisons/DCMP.h"
#include "control/RETURN.h"
#include "references/ARRAY_LENGTH.h"
#include "loads/XALOAD.h"
#include "stores/XASTORE.h"
#include "reserved/INVOKE_NATIVE.h"
#include "references/ATHROW.h"
#include <map>

namespace rt {

    class Factory {
    private:
        static NOP nop;
        static ACONST_NULL aconst_null;
        static ICONST_M1 iconst_m1;
        static ICONST_0 iconst_0;
        static ICONST_1 iconst_1;
        static ICONST_2 iconst_2;
        static ICONST_3 iconst_3;
        static ICONST_4 iconst_4;
        static ICONST_5 iconst_5;
        static LCONST_0 lconst_0;
        static LCONST_1 lconst_1;
        static FCONST_0 fconst_0;
        static FCONST_1 fconst_1;
        static FCONST_2 fconst_2;
        static DCONST_0 dconst_0;
        static DCONST_1 dconst_1;
        static ILOAD_0 iload_0;
        static ILOAD_1 iload_1;
        static ILOAD_2 iload_2;
        static ILOAD_3 iload_3;
        static LLOAD_0 lload_0;
        static LLOAD_1 lload_1;
        static LLOAD_2 lload_2;
        static LLOAD_3 lload_3;
        static FLOAD_0 fload_0;
        static FLOAD_1 fload_1;
        static FLOAD_2 fload_2;
        static FLOAD_3 fload_3;
        static DLOAD_0 dload_0;
        static DLOAD_1 dload_1;
        static DLOAD_2 dload_2;
        static DLOAD_3 dload_3;
        static ALOAD_0 aload_0;
        static ALOAD_1 aload_1;
        static ALOAD_2 aload_2;
        static ALOAD_3 aload_3;

        static ISTORE_0 istore_0;
        static ISTORE_1 istore_1;
        static ISTORE_2 istore_2;
        static ISTORE_3 istore_3;
        static LSTORE_0 lstore_0;
        static LSTORE_1 lstore_1;
        static LSTORE_2 lstore_2;
        static LSTORE_3 lstore_3;
        static FSTORE_0 fstore_0;
        static FSTORE_1 fstore_1;
        static FSTORE_2 fstore_2;
        static FSTORE_3 fstore_3;
        static DSTORE_0 dstore_0;
        static DSTORE_1 dstore_1;
        static DSTORE_2 dstore_2;
        static DSTORE_3 dstore_3;
        static ASTORE_0 astore_0;
        static ASTORE_1 astore_1;
        static ASTORE_2 astore_2;
        static ASTORE_3 astore_3;

        static Pop pop;
        static Pop2 pop2;
        static Dup dup;
        static Dup_X1 dup_x1;
        static Dup_X2 dup_x2;
        static Dup2 dup2;
        static Dup2_X1 dup2_x1;
        static Dup2_X2 dup2_x2;
        static Swap swap;
        static IADD iadd;
        static LADD ladd;
        static FADD fadd;
        static DADD dadd;
        static ISUB isub;
        static LSUB lsub;
        static FSUB fsub;
        static DSUB dsub;
        static IMUL imul;
        static LMUL lmul;
        static FMUL fmul;
        static DMUL dmul;
        static IDIV idiv;
        static LDIV ldiv;
        static FDIV fdiv;
        static DDIV ddiv;
        static IREM irem;
        static LREM lrem;
        static FREM frem;
        static DREM drem;
        static INEG ineg;
        static LNEG lneg;
        static FNEG fneg;
        static DNEG dneg;
        static ISHL ishl;
        static LSHL lshl;
        static ISHR ishr;
        static LSHR lshr;
        static IUSHR iushr;
        static LUSHR lushr;
        static IAND iand;
        static LAND land;
        static IOR ior;
        static LOR lor;
        static IXOR ixor;
        static LXOR lxor;
        static I2L i2l;
        static I2F i2f;
        static I2D i2d;

        static L2I l2i;
        static L2F l2f;
        static L2D l2d;
        static F2I f2i;
        static F2L f2l;
        static F2D f2d;
        static D2I d2i;
        static D2L d2l;
        static D2F d2f;

        static I2B i2b;
        static I2C i2c;
        static I2S i2s;


        static LCMP lcmp;
        static FCMPL fcmpl;
        static FCMPG fcmpg;
        static DCMPL dcmpl;
        static DCMPG dcmpg;

        static IRETURN ireturn;
        static LRETURN lreturn;
        static FRETURN freturn;
        static DRETURN dreturn;
        static ARETURN areturn;
        static RETURN _return;

        static ARRAY_LENGTH array_length;
        static IALOAD iaload;
        static LALOAD laload;
        static FALOAD faload;
        static DALOAD daload;
        static AALOAD aaload;
        static BALOAD baload;
        static CALOAD caload;
        static SALOAD saload;

        static IASTORE iastore;
        static LASTORE lastore;
        static FASTORE fastore;
        static DASTORE dastore;
        static AASTORE aastore;
        static BASTORE bastore;
        static CASTORE castore;
        static SASTORE sastore;

        static INVOKE_NATIVE invoke_native;

        static ATHROW athrow;

        static map<int, string>* s_instructionNames;

    public:
        static Instruction *newInstruction(byte opcode);
        static map<int, string>* initInstructionNames();
        static void releaseInstruction(Instruction* ptr, int opCode);
    };

}


#endif //JVM_FACTORY_H
